from collections import Counter
from pathlib import Path
from typing import TextIO


def solve(fp: TextIO):
    grid = dict()
    start = None
    rows = fp.read().splitlines()
    for i, row in enumerate(rows):
        for j, x in enumerate(row):
            z = complex(j, i)
            grid[z] = x
            if x == "S":
                start = z

    n_splits = 0
    beams = {start}
    cnt = Counter()
    cnt[start] = 1
    while beams:  # NOTE: it's easier to just scan the rows top-down than exhaust beams
        next_beams = set()
        for b in beams:
            nb = b + 1j
            if nb not in grid:
                continue
            if grid[nb] == "^":
                next_beams |= {nb - 1, nb + 1} & grid.keys()
                n_splits += 1
                cnt[nb - 1] += cnt[b]
                cnt[nb + 1] += cnt[b]
            else:
                next_beams |= {nb}
                cnt[nb] += cnt[b]
        beams = next_beams
        # TODO: viz grid here

    p1 = n_splits
    p2 = sum(v for z, v in cnt.items() if z.imag == len(rows) - 1)

    return p1, p2


def test_example():
    with open(Path(__file__).parent / "example") as fp:
        p1, p2 = solve(fp)

    assert p1 == 21
    assert p2 == 40


def main():
    with open(0) as fp:
        # with open("example") as fp:
        p1, p2 = solve(fp)

    print(f"Part 1: {p1}")
    print(f"Part 2: {p2}")


if __name__ == "__main__":
    main()
