import argparse
import shutil
import yaml
import traceback

import subprocess

from pathlib import Path


PLACEHOLDER_DIR_NAME = "tbd"


def get_args():
  parser = argparse.ArgumentParser(
      description="Utility to manage manual benchmarks")
  parser.add_argument(
      "--config", "-c", help="Path to config file", required=True)

  parser.add_argument("--generate-placeholders", action="store_true")
  parser.add_argument("--generate-patches", action="store_true")

  parser.add_argument("--apply-patches", action="store_true")
  parser.add_argument("--output", "-o", help="Path to output directory")

  return parser.parse_args()


def generate_placeholders(source_dir, source_list, patches):
  for patch in patches:
    _, patch_path = patch["name"], patch["path"]

    placeholder_dir = source_dir / patch_path / PLACEHOLDER_DIR_NAME
    placeholder_dir.mkdir(exist_ok=True, parents=True)

    for src_file in source_list:
      shutil.copyfile(src_file, placeholder_dir / src_file.name)


def generate_patches(source_dir, source_list, patches):
  for patch in patches:
    _, patch_path = patch["name"], patch["path"]
    placeholder_dir = source_dir / patch_path / PLACEHOLDER_DIR_NAME

    for src_file in source_list:
      patch_file = source_dir / patch_path / (src_file.name + ".diff")
      with patch_file.open("w") as f:
        try:
          subprocess.run(
              ["diff", "-u", src_file, placeholder_dir / src_file.name], stdout=f)
        except:
          traceback.print_exc()


def apply_patches(source_dir, source_list, patches, output_dir):
  shutil.rmtree(output_dir, ignore_errors=True)
  output_dir.mkdir(exist_ok=True, parents=True)

  for src_file in source_list:
    shutil.copyfile(src_file, output_dir / src_file.name)

  for patch in patches:
    _, patch_path = patch["name"], patch["path"]

    for src_file in source_list:
      diff_file = source_dir / patch_path / (src_file.name + ".diff")
      if not diff_file.exists():
        continue

      subprocess.run(["patch", "-p0", "-i", diff_file,
                     output_dir / src_file.name])


if __name__ == "__main__":
  args = get_args()

  assert len(list(filter(None, [args.generate_placeholders, args.generate_patches, args.apply_patches]))) == 1, \
      "Exactly one of --generate-placeholders, --generate-patches, --apply-patches must be specified"

  try:
    with open(args.config, "rb") as f:
      config = yaml.safe_load(f.read()) or {}
  except:
    traceback.print_exc()

  source_dir = Path(config["source_dir"])
  if not source_dir.is_absolute():
    source_dir = Path(args.config).parent / source_dir

  source_list = list(source_dir.glob(config["matches"]))
  patches = config["patches"]

  if args.generate_placeholders:
    generate_placeholders(source_dir, source_list, patches)
  elif args.generate_patches:
    generate_patches(source_dir, source_list, patches)
  elif args.apply_patches:
    assert args.output, "--output must be specified"
    apply_patches(source_dir, source_list, patches,
                  Path(args.output).resolve())
