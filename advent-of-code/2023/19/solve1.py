import ast
import re
from collections import defaultdict
from pathlib import Path
from typing import TextIO


def get_inp(fp):
    rs, xs = fp.read().split("\n\n")

    rules = defaultdict(list)
    for r in rs.split("\n"):
        name, checks = re.match("([a-z]+){(.*)}", r).groups()
        for check in checks.split(","):
            if ":" in check:  # composite rule, maybe there's a nicer way to do this
                cond, send = check.split(":")
                cond = re.sub(r"([a-z])", r'd["\1"]', cond)
                rules[name].append(eval(f"lambda d: '{send}' if {cond} else None"))
            else:  # simple rule, matches everything
                rules[name].append(eval(f"lambda d: '{check}'"))

    dicts = [
        ast.literal_eval(re.sub(r"([a-z])", r'"\1"', x.replace("=", ":")))
        for x in xs.strip().split("\n")
    ]

    return rules, dicts


def apply(x: dict, rules: dict[str, callable]) -> bool:
    z = "in"

    while True:
        for f in rules[z]:
            if m := f(x):
                z = m
                break
        if z == "A":
            return True
        if z == "R":
            return False


def solve(fp: TextIO):
    rules, dicts = get_inp(fp)
    return sum(sum(d.values()) for d in dicts if apply(d, rules))


def test_example():
    with open(Path(__file__).parent / "example") as fp:
        assert solve(fp) == 19114


def main():
    with open(0) as fp:
        print(f"Part 1: {solve(fp)}")


if __name__ == "__main__":
    main()
