import subprocess
import os
import glob
import yaml

from pathlib import Path
from shutil import copy
from collections import namedtuple

CONFIG_DIR = "./configs"
OUTPUT_DIR = "./bin"
SOURCE_DIR = "./samples"
TIGRESS_HOME = "./tigress/3.3.2"

TIGRESS_ENV = "x86_64:Linux:Gcc:4.6"
TIGRESS_PARAMS = [f"--Environment={TIGRESS_ENV}"]

TigressConfig = namedtuple("TigressConfig", ["description", "params", "variants"])
TigressVariant = namedtuple("TigressVariant", ["name", "procedure"])


def call_tigress(tigress_home, params, src_file, out_file):
    try:
        os.environ["TIGRESS_HOME"] = tigress_home
        tigress_exec = os.path.join(tigress_home, "tigress")

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

def run_tigress(config: TigressConfig) -> None:

    src_dir = Path.cwd() / SOURCE_DIR

    for variant in config.variants:

        # ensure dir exists
        out_dir = Path.cwd() / Path(OUTPUT_DIR) / config.description / variant.name
        out_dir.mkdir(parents=True, exist_ok=True)

        for src_file in glob.glob(os.path.join(SOURCE_DIR, "*.c")):

            src_name = Path(src_file).stem
            src_in_file = out_dir / (src_name + ".in.c")
            src_out_file = out_dir / (src_name + ".out.c")

            # copy source file to out_dir with .in suffix
            header_file = src_dir / (src_name + ".h")
            if header_file.exists(): copy(header_file, out_dir)
            copy(src_file, src_in_file)

            # sequentially apply transformation to C file
            for proc in variant.procedure:
                call_tigress(TIGRESS_HOME, config.params + proc, src_in_file, src_out_file)
                copy(src_out_file, src_in_file)

            os.remove(src_in_file)

    


if __name__ == "__main__":
   
    for config_file in glob.glob(os.path.join(CONFIG_DIR, "*.yml")):
        with open(config_file, "rb") as f:
            config = yaml.safe_load(f.read()) or {}
            config["variants"] = [TigressVariant(**variant) for variant in config["variants"]]
            config = TigressConfig(**config)

            run_tigress(config)

