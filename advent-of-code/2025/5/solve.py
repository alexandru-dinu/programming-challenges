from functools import partial
from pathlib import Path
from typing import TextIO


def in_range(x, rs):
    for r in rs:
        if x < r.start:
            break
        if x in r:
            return True

    return False


def merge(r1, r2):
    if r2.start > r1.stop:  # not joinable
        return None

    lo = min(r1.start, r2.stop)
    hi = max(r1.stop, r2.stop)
    assert lo <= hi
    return range(lo, hi)


def solve(fp: TextIO):
    rs, ings = fp.read().split("\n\n")

    ings = [int(i) for i in ings.splitlines()]

    rs = [r.split("-") for r in rs.splitlines()]
    rs = [range(int(r[0]), int(r[1]) + 1) for r in rs]
    rs = sorted(rs, key=lambda r: (r.start, r.stop))

    p1 = sum(map(partial(in_range, rs=rs), ings))

    cur, *rest = rs
    out = [cur]
    for r in rest:
        if res := merge(cur, r):
            out.pop()
            out.append(res)
            cur = res
        else:
            out.append(r)
            cur = r

    p2 = sum(len(r) for r in out)

    return p1, p2


def test_example():
    with open(Path(__file__).parent / "example") as fp:
        p1, p2 = solve(fp)

    assert p1 == 3
    assert p2 == 14


def main():
    with open(0) as fp:
        p1, p2 = solve(fp)

    print(f"Part 1: {p1}")
    print(f"Part 2: {p2}")


if __name__ == "__main__":
    main()
