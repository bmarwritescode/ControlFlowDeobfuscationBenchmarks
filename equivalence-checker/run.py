from __future__ import annotations

from datetime import timedelta
from hypothesis import given, strategies as st, settings, Phase
from subprocess import run as subprocess_run, CalledProcessError

import argparse
import os
import tempfile
import unittest

HYPOTHESIS_TYPE = {
    "long": st.integers(min_value=0, max_value=2**31),
    "bool": st.booleans()
}

HYPOTHESIS_SETTINGS = {
    "max_examples": 100,
    "deadline": timedelta(seconds=20),
    "phases": [Phase.generate]
}


def _compile(src_path: str) -> str:
  try:
    _, out_path = tempfile.mkstemp()
    result = subprocess_run(["gcc", "-o", out_path, src_path],
                            capture_output=True, check=True, timeout=10, encoding="utf8")

    assert result.returncode == 0
    return out_path
  except CalledProcessError as ex:
    print(ex.stdout)
    print(ex.stderr)
    return None


def _run_program(exec_path: str, args: list[str]) -> str:
  try:
    result = subprocess_run(
        [exec_path] + args, capture_output=True, check=True, timeout=10, encoding="utf8")
    return result.stdout
  except CalledProcessError as ex:
    return ex.stderr


def _create_test_driver(prog_1: str, prog_2: str, test_settings: dict) -> callable[[int], None]:

  class TestProgramEquivalence(unittest.TestCase):
    @given(value=HYPOTHESIS_TYPE["long"])
    @settings(**test_settings)
    def test_equiv(self: "TestProgramEquivalence", value: int) -> None:
      out_1 = _run_program(prog_1, [str(value)])
      out_2 = _run_program(prog_2, [str(value)])

      self.assertEqual(out_1, out_2)

  return TestProgramEquivalence


def run_test(src_1_path: str, src_2_path: str) -> None:

  try:
    prog_1 = _compile(src_1_path)
    prog_2 = _compile(src_2_path)

    if not prog_1 or not prog_2:
      raise Exception("Cannot compile C programs")

    test_driver = _create_test_driver(prog_1, prog_2, HYPOTHESIS_SETTINGS)

    runner = unittest.TextTestRunner()
    runner.run(unittest.makeSuite(test_driver))
  finally:
    try:
      os.remove(prog_1)
      os.remove(prog_2)
    except:
      pass


if __name__ == "__main__":
  parser = argparse.ArgumentParser(
      description="Test two given C programs produce the same output.")
  parser.add_argument("path_to_src_1")
  parser.add_argument("path_to_src_2")
  args = parser.parse_args()

  run_test(args.path_to_src_1, args.path_to_src_2)
