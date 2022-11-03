import argparse
import os
import subprocess
import yaml

from pathlib import Path
from shutil import copy, which
from collections import namedtuple
from dataclasses import dataclass

# specify tigress path if not installed
TIGRESS_HOME = "./tigress/3.3.2"
TIGRESS_ENV = "--Environment=x86_64:Linux:Gcc:4.6"
TIGRESS_PARAMS = [f"--Environment={TIGRESS_ENV}"]

@dataclass(frozen=True)
    name: str
    func: str
    procedure: list[list[str]]


@dataclass(frozen=True)
class TigressConfig:
    description: str
    params: list[str]
    variants: list[TigressVariant]


def get_args():
    """
    Parse command line arguments
    """
    parser = argparse.ArgumentParser(
        description="Iteratively apply Tigress transformations to C files")
    parser.add_argument(
        "--config", "-c", help="Path to config file", required=True)
    parser.add_argument(
        "--output", "-o", help="Path to output directory", required=True)
    parser.add_argument("--input-dir", "-i",
                        help="Path to input directory", required=True)

    return parser.parse_args()


def call_tigress(tigress_home, params, src_file, out_file):
    # setup Tigress environment and path
    tigress_exec = which("tigress")
    if tigress_exec is None:
        os.environ["TIGRESS_HOME"] = tigress_home
        tigress_exec = os.path.join(tigress_home, "tigress")

    try:
        output = subprocess.run([tigress_exec, f"--out={out_file}"] + TIGRESS_PARAMS + params + [src_file],
                                encoding="utf8",
                                check=True,
                                stdout=subprocess.PIPE,
                                stderr=subprocess.PIPE).stdout
        return output.strip()
    except subprocess.CalledProcessError as ex:
        print(ex.output)
        print(ex.stderr)
        print(ex)


def run_tigress(config: TigressConfig, source_dir: Path, output_dir: Path) -> None:

    for variant in config.variants:

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
                call_tigress(TIGRESS_HOME, config.params +
                             proc, src_in_file, src_out_file)
                copy(src_out_file, src_in_file)

            os.remove(src_in_file)


if __name__ == "__main__":

    args = get_args()
    with open(args.config, "rb") as f:
        config = yaml.safe_load(f.read()) or {}
        config["variants"] = [TigressVariant(
            **variant) for variant in config["variants"]]
        config = TigressConfig(**config)

    source_dir = Path(args.input_dir).resolve()
    output_dir = Path(args.output).resolve()
    run_tigress(config, source_dir, output_dir)
