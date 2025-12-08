from collections import Counter
from itertools import combinations
from math import prod
from pathlib import Path
from typing import TextIO


def dist(a, b):
    return sum((i - j) ** 2 for i, j in zip(a, b))


def union(parents, i, j):
    irep = find(parents, i)
    jrep = find(parents, j)
    if irep == jrep:
        return
    parents[irep] = jrep


def find(parents, i):
    if parents[i] == i:
        return i

    parents[i] = find(parents, parents[i])

    return parents[i]


def solve_p1(ps, dists, iters):
    assert 0 < iters <= len(dists)
    parents = {i: i for i in range(len(ps))}

    for i, (d, u, v) in enumerate(dists[:iters]):
        union(parents, u, v)

    cnt = Counter()
    for i in range(len(ps)):
        cnt[find(parents, i)] += 1

    return prod(v for _, v in cnt.most_common()[:3])


def solve_p2(ps, dists):
    parents = {i: i for i in range(len(ps))}

    cs = 0
    for d, u, v in dists:
        if find(parents, u) != find(parents, v):
            union(parents, u, v)
            cs += 1
            if cs == len(ps) - 1:
                return ps[u][0] * ps[v][0]


def solve(fp: TextIO, iters: int):
    ps = [tuple(map(int, x.split(","))) for x in fp.read().strip().split("\n")]

    comb = set(combinations(range(len(ps)), 2))

    # sort by shortest connections
    dists = sorted([(dist(ps[i], ps[j]), i, j) for (i, j) in comb])

    p1 = solve_p1(ps, dists, iters)
    p2 = solve_p2(ps, dists)

    return p1, p2


def test_example():
    with open(Path(__file__).parent / "example") as fp:
        p1, p2 = solve(fp, iters=10)

    assert p1 == 40
    assert p2 == 25272


def main():
    with open(0) as fp:
        p1, p2 = solve(fp, iters=1000)

    print(f"Part 1: {p1}")
    print(f"Part 2: {p2}")


if __name__ == "__main__":
    main()
