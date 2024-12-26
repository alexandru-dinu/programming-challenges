from itertools import product
from pathlib import Path
from typing import TextIO

import numpy as np

H, W = 7, 5


def solve(fp: TextIO):
    zs = [[], []]
    for xs in fp.read().strip().split("\n\n"):
        x = np.array([list(r) for r in xs.split()])
        zs[int((x[0] == "#").all())].append(np.cumsum(x == "#", axis=0)[-1] - 1)

    return sum((k + l < H - 1).all() for k, l in product(*zs))


def test_example():
    with open(Path(__file__).parent / "example") as fp:
        assert 3 == solve(fp)


def main():
    with open(0) as fp:
        print(f"Solution: {solve(fp)}")


if __name__ == "__main__":
    main()
