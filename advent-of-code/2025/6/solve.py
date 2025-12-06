from itertools import groupby
from pathlib import Path
from typing import TextIO

import numpy as np

OPS = {"*": np.prod, "+": np.sum}


def solve(fp: TextIO):
    raw = fp.read()
    *nums, ops = raw.splitlines()
    ops = ops.strip().split()

    xss = np.array([xs.strip().split() for xs in nums]).astype(int)
    p1 = sum(OPS[op](xss[:, i]) for i, op in enumerate(ops))

    # p2 = 0
    # xs = []
    # # append a dummy space so we can treat first col w/o duplicating code
    # nums = [" " + x for x in nums]
    # ops = reversed(ops)
    # for i in reversed(range(len(nums[0]))):
    #     x = "".join(row[i] for row in nums if not row[i].isspace())
    #     if not x:
    #         p2 += OPS[next(ops)](xs).item()
    #         xs = []
    #     else:
    #         xs.append(int(x))

    # upsolve
    p2 = sum(
        OPS[op](xs)
        for op, xs in zip(
            ops,
            [
                list(g)
                for f, g in groupby(
                    [int("".join(x).strip() or "0") for x in zip(*nums)],
                    lambda k: k != 0,
                )
                if f
            ],
            strict=True,
        )
    )

    return p1, p2


def test_example():
    with open(Path(__file__).parent / "example") as fp:
        p1, p2 = solve(fp)

    assert p1 == 4277556
    assert p2 == 3263827


def main():
    with open(0) as fp:
        p1, p2 = solve(fp)

    print(f"Part 1: {p1}")
    print(f"Part 2: {p2}")


if __name__ == "__main__":
    main()
