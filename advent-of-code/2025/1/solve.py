from pathlib import Path
from typing import TextIO


def iterate1(xs: list[int]):
    y = 50
    return sum(0 == (y := ((x + y) % 100)) for x in xs)


def iterate2(xs: list[int]):
    y = 50
    res = 0
    for x in xs:
        assert 0 <= y < 100
        w, y_ = divmod(y + x, 100)
        res += (
            # number of passes through 0
            abs(w)
            # account for false pass when starting from 0 and going L
            - (y == 0 and x < 0)
            # account for missing pass (w == 0) when reaching 0
            + (y_ == 0 and x < 0)
        )
        y = y_

    return res


def solve(fp: TextIO):
    xs = [int(x[1:]) * {"L": -1, "R": 1}[x[0]] for x in fp.readlines()]

    p1 = iterate1(xs)
    p2 = iterate2(xs)

    return p1, p2


def test_example():
    with open(Path(__file__).parent / "example") as fp:
        p1, p2 = solve(fp)

    assert p1 == 3
    assert p2 == 6


def main():
    with open(0) as fp:
        p1, p2 = solve(fp)

    print(f"Part 1: {p1}")
    print(f"Part 2: {p2}")


if __name__ == "__main__":
    main()
