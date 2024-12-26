from collections import deque
from functools import reduce
from itertools import pairwise
from pathlib import Path
from typing import TextIO

import numpy as np


def read_inp(fp):
    return np.array([list(x.strip()) for x in fp])


def neighbours(g, u):
    h, w = g.shape
    i, j = u

    for di, dj in [(0, 1), (0, -1), (-1, 0), (1, 0)]:
        ni = i + di
        nj = j + dj

        if not (0 <= ni < h and 0 <= nj < w) or g[ni, nj] == "#":
            continue

        # TODO: simplify
        match g[ni, nj]:
            case ">":
                yield (ni, nj), (ni, nj + 1)
            case "<":
                yield (ni, nj), (ni, nj - 1)
            case "v":
                yield (ni, nj), (ni + 1, nj)
            case "^":
                yield (ni, nj), (ni - 1, nj)
            case ".":
                yield None, (ni, nj)


def all_paths(g, src, dst):
    path = [src]
    q = [path.copy()]

    while q:
        c_path = q.pop()
        last = c_path[-1]

        if last == dst:
            yield c_path.copy()[1:]  # w/o start

        for v1, v2 in neighbours(g, last):
            if v2 not in c_path:
                if v1 is None:
                    n_path = [*c_path, v2]
                else:
                    n_path = [*c_path, v1, v2]
                q.append(n_path)


class Region:
    def __init__(self, start):
        self.start = start
        self.end = None
        self.nodes = []
        self.nei = []

    def __hash__(self):
        return hash((self.start, self.end))

    def __len__(self):
        return len(self.nodes)

    def __eq__(self, other):
        return self.start == other.start and self.end == other.end


def aug_dfs(src, dst):
    assert src.start == (0, 1)

    path = [src]
    q = [path.copy()]

    while q:
        c_path = q.pop()
        last = c_path[-1]

        if last.end == dst:
            yield c_path.copy()

        for n in last.nei:
            if n not in c_path:
                q.append([*c_path, n])


def debug(g):
    def dfs(src: tuple, dst: tuple):
        nonlocal g_vis

        q = [src]
        vis = set()

        while q:
            u = q.pop()
            if u in vis or u in g_vis:
                continue
            vis.add(u)

            if u == dst:
                return vis, dst, []

            nei = [v for _, v in neighbours(g, u)]
            nxt = [v for v in nei if v not in vis and v not in g_vis]

            if len(nei) <= 2:  # inside a run (or dead-end)
                q.extend(nxt)
            else:  # junction
                return vis, u, nxt

        return vis, None, []

    h, w = g.shape
    dst = (h - 1, w - 2)

    frontier = deque([Region(start=(0, 1))])
    g_vis = set()
    regions = []

    intersections = []

    while frontier:
        c_reg = frontier.popleft()
        reg_nodes, last, nxt = dfs(c_reg.start, dst)
        c_reg.nodes = list(reg_nodes)
        c_reg.end = last

        new_reg = [Region(start=n) for n in nxt]
        frontier.extend(new_reg)

        if last is not None and last != dst:
            intersections.append(last)

        if len(reg_nodes) > 0:
            g_vis |= reg_nodes
            regions.append(c_reg)
            for n_reg in new_reg:
                n_reg.nei.append(c_reg)
                c_reg.nei.append(n_reg)

    for r in regions:
        if r.end == dst:
            print(f"{r.start}..{r.end} ***")
        else:
            print(f"{r.start}..{r.end}")
        # print('\t', r.nodes)
        for n in r.nei:
            print("\t->", n.start)

    # regions are pairwise disjoint
    for r1, r2 in pairwise(regions):
        assert set(r1.nodes) & set(r2.nodes) == set()
    # regions cover the entire space
    assert reduce(set.union, map(lambda r: set(r.nodes), regions)) == set(
        map(tuple, np.argwhere(g == "."))
    )

    paths = aug_dfs(regions[0], dst)
    for p in paths:
        print(sum(map(len, p)))

    # if 0:
    #     print(f"{len(regions)=}")
    #     for r in regions:
    #         print(r)
    #     print(f"{intersections=}")
    #     for x in intersections:
    #         g[x] = 'o'

    #     print('\n'.join(''.join(r) for r in g))
    #     # TODO: need to reconstruct the region graph


def solve(fp: TextIO):
    g = read_inp(fp)
    h, w = g.shape

    src = (0, 1)
    dst = (h - 1, w - 2)

    p1 = max(map(len, all_paths(g, src, dst)))

    g[np.isin(g, list("<>^v"))] = "."
    debug(g)
    p2 = ...
    return p1, p2


def test_example():
    with open(Path(__file__).parent / "example") as fp:
        g = read_inp(fp)

    h, w = g.shape
    src = (0, 1)
    dst = (h - 1, w - 2)
    assert sorted(map(len, all_paths(g, src, dst))) == [
        74,
        82,
        82,
        86,
        90,
        94,
    ]

    g[np.isin(g, list("<>^v"))] = "."
    assert max(map(len, all_paths(g, src, dst))) == 154


def main():
    with open(0) as fp:
        p1, p2 = solve(fp)

    print(f"Part 1: {p1}")
    print(f"Part 2: {p2}")


if __name__ == "__main__":
    main()
