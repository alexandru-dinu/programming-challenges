from pathlib import Path
from typing import TextIO

import numpy as np
import z3


def parse_line(x):
    goal, rest = x.split(" ", maxsplit=1)
    btns, jolt = rest.rsplit(" ", maxsplit=1)

    goal = [".#".index(x) for x in goal[1:-1]]
    n = len(goal)

    btns_mat = []
    for btn in btns.split(" "):
        b = np.zeros(n, dtype=int)
        b[list(map(int, btn[1:-1].split(",")))] = 1
        btns_mat.append(b)

    jolt = list(map(int, jolt[1:-1].split(",")))

    return np.array(goal), np.array(btns_mat).T, np.array(jolt)


def sat_one(goal, btns, jolt=None):
    n_goal, n_btns = btns.shape
    assert len(goal) == n_goal

    opt = z3.Optimize()

    X = [z3.Int(f"x_{i}") for i in range(n_btns)]

    for i in range(n_btns):
        opt.add(X[i] >= 0)

    for i in range(n_goal):
        s = z3.Sum([btns[i, j] * X[j] for j in range(n_btns)])
        if jolt is not None:
            opt.add(s == jolt[i])
        else:
            opt.add(s % 2 == goal[i])  # TODO: remove mod in favour of A*X=B+2Y ?

    opt.minimize(z3.Sum(X))

    assert opt.check() == z3.sat
    sol = [opt.model()[x].as_long() for x in X]

    return sum(sol)


def solve(fp: TextIO):
    xs = [parse_line(x.strip()) for x in fp.readlines()]

    p1 = p2 = 0
    for g, b, j in xs:
        p1 += sat_one(goal=g, btns=b, jolt=None)
        p2 += sat_one(goal=g, btns=b, jolt=j)

    return p1, p2


def test_example():
    with open(Path(__file__).parent / "example") as fp:
        p1, p2 = solve(fp)

    assert p1 == 7
    assert p2 == 33


def main():
    with open(0) as fp:
        p1, p2 = solve(fp)

    print(f"Part 1: {p1}")
    print(f"Part 2: {p2}")


if __name__ == "__main__":
    main()
