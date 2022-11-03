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


@dataclass(frozen=True)
class TigressVariant:
    name: str
    procedure: list[list[str]] = field(default_factory=list)
    args: dict[str, str] = field(default_factory=dict)
    format: bool = True


@dataclass(frozen=True)
class TigressConfig:
    description: str
    params: list[str]
    variants: list[TigressVariant]
    args: dict[str, str] = field(default_factory=dict)


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

        if not variant.procedure:
            continue

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

            # sequentially apply transformation to C file
            for proc in variant.procedure:
                proc = [p.format(**{**config.args, **variant.args}) for p in proc]

                out = call_tigress(
                    TIGRESS_HOME,
                    config.params + proc,
                    str(src_in_file),
                    str(src_out_file),
                )
                if out:
                    print(f"===== {variant.name} ({src_name}): ===== {out}\n")
                copy(src_out_file, src_in_file)

            os.remove(src_in_file)

            if variant.format:
                format_c_source(str(src_out_file))


def format_c_source(src_path: str) -> None:
    FORMAT_COMMAND = ["clang-format", "--style=Google", "-i", src_path]
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

    args = get_args()
    with open(args.config, "rb") as f:
        config = yaml.safe_load(f.read()) or {}
        config["variants"] = [
            TigressVariant(**variant) for variant in config["variants"]
        ]
        config = TigressConfig(**config)

    source_dir = Path(args.input_dir).resolve()
    output_dir = Path(args.output).resolve()
    run_tigress(config, source_dir, output_dir)
