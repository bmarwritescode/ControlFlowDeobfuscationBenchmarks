from typing import Any
from pathlib import Path
from shutil import copy, which
from dataclasses import dataclass, field
from argparse import ArgumentParser, Namespace

import os
import subprocess
import yaml

TIGRESS_HOME = "./tigress/3.3.2"
TIGRESS_ENV = "x86_64:Linux:Gcc:4.6"
TIGRESS_PARAMS = [f"--Environment={TIGRESS_ENV}"]
CLANG_FORMAT_STYLE = "{ColumnLimit: 114514}"


@dataclass(frozen=True)
class TigressTemplateCall:
    template: str
    args: dict[str, str] = field(default_factory=dict)


@dataclass(frozen=True)
class TigressVariant:
    name: str
    procedure: list[list[str]] = field(default_factory=list)
    use: list[TigressTemplateCall] = field(default_factory=list)
    args: dict[str, str] = field(default_factory=dict)
    format: bool = True


@dataclass(frozen=True)
class TigressConfig:
    description: str
    params: list[str]
    variants: list[TigressVariant]
    templates: dict[str, TigressVariant] = field(default_factory=dict)
    args: dict[str, str] = field(default_factory=dict)

def _format_arg(x: Any) -> str:
    if isinstance(x, bool):
        return str(x).lower()
    return str(x)


def get_args() -> Namespace:
    """
    Parse command line arguments
    """
    parser = ArgumentParser(
        description="Iteratively apply Tigress transformations to C files"
    )
    parser.add_argument("--config", "-c", help="Path to config file", required=True)
    parser.add_argument(
        "--output", "-o", help="Path to output directory", required=True
    )
    parser.add_argument(
        "--input-dir", "-i", help="Path to input directory", required=True
    )

    return parser.parse_args()


def call_tigress(
    tigress_home: str, params: list[str], src_file: str, out_file: str
) -> str:
    # setup Tigress environment and path
    tigress_exec = which("tigress")
    if tigress_exec is None:
        os.environ["TIGRESS_HOME"] = tigress_home
        tigress_exec = os.path.join(tigress_home, "tigress")

    try:
        output = subprocess.run(
            [tigress_exec, f"--out={out_file}"] + TIGRESS_PARAMS + params + [src_file],
            encoding="utf8",
            check=True,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
        ).stdout
        return output.strip()
    except subprocess.CalledProcessError as ex:
        return "".join([ex.output, ex.stderr, str(ex)])


def run_tigress(config: TigressConfig, source_dir: Path, output_dir: Path) -> None:

    for variant in config.variants:

        if not variant.procedure and not variant.use:
            continue

        assert bool(variant.procedure) != bool(
            variant.use
        ), "procedure and use cannot both have value"

        # ensure dir exists
        out_dir = output_dir / config.description / variant.name
        out_dir.mkdir(parents=True, exist_ok=True)

        for src_file in source_dir.glob("*.c"):

            src_name = src_file.stem
            src_in_file = out_dir / (src_name + ".in.c")
            src_out_file = out_dir / (src_name + ".out.c")

            # copy source file to out_dir with .in suffix
            header_file = source_dir / (src_name + ".h")
            if header_file.exists():
                copy(header_file, out_dir)
            copy(src_file, src_in_file)

            procedure_with_args = None
            if variant.procedure:
                procedure_with_args = [(variant.procedure, variant.args)]
            elif variant.use:
                assert all(
                    call.template in config.templates for call in variant.use
                ), f"cannot find template in {variant}"
                procedure_with_args = [
                    (
                        config.templates[call.template].procedure,
                        {**config.templates[call.template].args, **call.args},
                    )
                    for call in variant.use
                ]
            assert procedure_with_args is not None

            # sequentially apply transformation to C file
            for procs, args in procedure_with_args:
                for proc in procs:
                    args = {**config.args, **variant.args, **args}
                    args = {k: _format_arg(v) for k, v in args.items()}
                    proc = [p.format(**args) for p in proc]

                    out = call_tigress(
                        TIGRESS_HOME,
                        config.params + proc,
                        str(src_in_file),
                        str(src_out_file),
                    )
                    if out:
                        print(f"===== {variant.name} ({src_name}): ===== \n{out}\n")
                    copy(src_out_file, src_in_file)

            os.remove(src_in_file)

            if variant.format:
                format_c_source(str(src_out_file))


def format_c_source(src_path: str) -> None:
    FORMAT_COMMAND = ["clang-format", "-style", CLANG_FORMAT_STYLE, "-i", src_path]
    PREPROCESS_COMMAND = [
        "gcc",
        "-E",
        src_path,
    ]
    HEADERS = """#define __attribute__(x)
#define __extension__
#define __restrict
#define __inline
#define __asm__(x)

typedef void* __builtin_va_list;"""
    with open(src_path, "r") as src_file:
        src_lines = src_file.readlines()

    with open(src_path, "w") as src_file:
        src_file.write(HEADERS)
        src_file.writelines(src_lines)

    # preprocess the source file for headers, comments removal etc.
    out_preproc = subprocess.check_output(PREPROCESS_COMMAND)
    src_lines = out_preproc.decode("utf8").splitlines()

    # remove lines that are not part of the source code
    src_lines = [
        line for line in src_lines if not line.startswith("#") and line.strip()
    ]

    with open(src_path, "w") as f:
        f.write("\n".join(src_lines))

    # format the source file
    subprocess.run(FORMAT_COMMAND, check=True)


if __name__ == "__main__":

    def load_variant(variant_dict: dict) -> TigressVariant:
        if "use" in variant_dict:
            variant_dict["use"] = [
                TigressTemplateCall(**v) for v in variant_dict["use"]
            ]
        return TigressVariant(**variant_dict)

    def load_templates(config_dict: dict) -> dict[str, TigressVariant]:
        templates: dict[str, TigressVariant] = {}

        for template_dict in config_dict["templates"]:
            # template dict = tigress variant
            name = template_dict["name"]
            procedure = template_dict.get("procedure", [])
            use = template_dict.get("use", [])
            args = template_dict.get("args", {})

            assert bool(procedure) != bool(use), "invalid format"
            if use:
                assert use.template in templates, "cannot find template"
                procedure = templates[use.template].procedure
            templates[name] = TigressVariant(name, procedure, args=args)

        return templates

    args = get_args()
    with open(args.config, "rb") as f:
        config = yaml.safe_load(f.read()) or {}
        config["variants"] = [load_variant(variant) for variant in config["variants"]]
        config["templates"] = load_templates(config)
        config = TigressConfig(**config)

    source_dir = Path(args.input_dir).resolve()
    output_dir = Path(args.output).resolve()
    run_tigress(config, source_dir, output_dir)
