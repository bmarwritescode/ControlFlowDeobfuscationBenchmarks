from typing import Any
from pathlib import Path
from shutil import copy, which
from dataclasses import dataclass, field
from argparse import ArgumentParser, Namespace
from collections import ChainMap
from itertools import product, chain, combinations
from operator import getitem
from functools import partial

import os
import subprocess
import yaml

from run import TigressTemplateCall, TigressVariant, TigressConfig


@dataclass(slots=True, frozen=True)
class TransformationOptions:
    name: str
    transform: str
    params: dict[str, list[str]] = field(default_factory=dict)


@dataclass(slots=True, frozen=True)
class Config:
    global_params: list[str]
    prelude: list[str]
    postlude: list[str]
    operations: dict[str, list[str]]
    options: dict[str, TransformationOptions]

    def __post_init__(self):
        for op, items in self.operations.items():
            for entry in items:
                if entry not in self.options:
                    raise ValueError(f"Unknown option {entry} for operation {op}")


def load_config(path: Path) -> Config:
    with open(path) as f:
        config = yaml.safe_load(f)
        config["options"] = [
            TransformationOptions(**option) for option in config["options"]
        ]
        config["options"] = dict((option.name, option) for option in config["options"])
        config["operations"] = dict(ChainMap(*config["operations"]))

        return Config(**config)


def expand_option(option: TransformationOptions) -> list[tuple[str, ...]]:
    params = []
    for param_options in product(*option.params.values()):
        param_options = tuple(
            map(lambda p: f"--{p[0]}={p[1]}", zip(option.params.keys(), param_options))
        )
        params.append((f"--Transform={option.transform}",) + param_options)
    return params


def generate_tigress_params(
    config: Config, num_operations: int
) -> list[tuple[str, ...]]:
    """
    Generate all possible combinations of Tigress parameters
    """
    params: list[tuple[str, ...]] = []

    expanded_options = {
        k: expand_option(option) for k, option in config.options.items()
    }
    expanded_operations = {
        name: list(chain.from_iterable(expanded_options[op] for op in ops))
        for name, ops in config.operations.items()
    }
    for combs in combinations(expanded_operations, num_operations):
        params.extend(
            map(
                tuple,
                map(
                    chain.from_iterable,
                    product(*[expanded_operations[comb] for comb in combs]),
                ),
            )
        )
    # add prelude and postlude

    prelude = list(map(tuple, map(chain.from_iterable, product(*map(partial(getitem, expanded_options), config.prelude)))))
    postlude = list(map(tuple, map(chain.from_iterable, product(*map(partial(getitem, expanded_options), config.postlude)))))

    params = list(map(lambda p: tuple(chain.from_iterable(p)), product(prelude, params, postlude)))
    return params


res = load_config(Path("./tigress/configs/options.yml"))
generate_tigress_params(res, 1)

# def generate_tigress_params(num_operations: int) -> list[tuple[str, ...]]:
#     """
#     Generate all possible combinations of Tigress parameters
#     """
#     params = []
#     for i in range(num_operations):
#         params.append((f"--Operation{i}=", f"--Operation{i}={i}"))
#     return params
