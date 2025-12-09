from itertools import combinations, pairwise, starmap
from pathlib import Path
from typing import TextIO


def area(x, y):
    return (abs(x[0] - y[0]) + 1) * (abs(x[1] - y[1]) + 1)


def solve(fp: TextIO):
    ps = [tuple(map(int, x.split(","))) for x in fp.readlines()]

    p1 = max(starmap(area, combinations(ps, 2)))

    ps_ = ps + [ps[0]]
    max_area = 0
    for (x1, y1), (x2, y2) in combinations(ps, 2):
        l = min(x1, x2)
        t = min(y1, y2)
        r = max(x1, x2)
        b = max(y1, y2)

        # NOTE: the input is given nicely, the outer path is traced clockwise, so we can iterate like this
        for (sx1, sy1), (sx2, sy2) in pairwise(ps_):
            # min/max are slow for 2 elems
            all_left = (sx1 if sx1 >= sx2 else sx2) <= l
            all_right = (sx1 if sx1 <= sx2 else sx2) >= r
            all_top = (sy1 if sy1 >= sy2 else sy2) <= t
            all_bot = (sy1 if sy1 <= sy2 else sy2) >= b
            if not (all_left or all_right or all_top or all_bot):  # segment intersects
                break
        else:  # no segments intersect the rectangle
            max_area = max(max_area, area((x1, y1), (x2, y2)))

    p2 = max_area
    return p1, p2


def test_example():
    with open(Path(__file__).parent / "example") as fp:
        p1, p2 = solve(fp)

    assert p1 == 50
    assert p2 == 24


def main():
    with open(0) as fp:
        p1, p2 = solve(fp)

    print(f"Part 1: {p1}")
    print(f"Part 2: {p2}")


if __name__ == "__main__":
    main()
