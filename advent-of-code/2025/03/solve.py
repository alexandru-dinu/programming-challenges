from functools import partial
from pathlib import Path
from typing import TextIO

import numpy as np


def amax(xs):
    a = np.argmax(xs).item()
    return a, xs[a]


def findmax(xs: str, tot: int) -> int:
    n = len(xs)
    ys = 0
    i = 0
    need = tot
    while need > 0:
        j, y = amax(list(map(int, xs[i : n - (need - 1)])))
        ys = ys * 10 + y
        i += j + 1
        need -= 1

    return ys


def solve(fp: TextIO):
    xs = [x.strip() for x in fp.readlines()]

    p1 = sum(map(partial(findmax, tot=2), xs))
    p2 = sum(map(partial(findmax, tot=12), xs))

    return p1, p2


def test_example():
    with open(Path(__file__).parent / "example") as fp:
        p1, p2 = solve(fp)

    assert p1 == 357
    assert p2 == 3121910778619


def main():
    with open(0) as fp:
        p1, p2 = solve(fp)

    print(f"Part 1: {p1}")
    print(f"Part 2: {p2}")


if __name__ == "__main__":
    main()
