from pathlib import Path
from typing import TextIO


def nei(z):
    def inner(z):
        for dz in [-1 - 1j, -1j, 1 - 1j, -1, 1, -1 + 1j, 1j, 1 + 1j]:
            yield z + dz

    return set(inner(z))


def solve(fp: TextIO):
    grid = {
        complex(j, i)
        for i, row in enumerate(fp.readlines())
        for j, z in enumerate(row)
        if z == "@"
    }

    p1 = sum(1 for z in grid if len(nei(z) & grid) < 4)

    p2 = 0
    while True:
        removable = {z for z in grid if len(nei(z) & grid) < 4}
        if not removable:
            break
        grid -= removable
        p2 += len(removable)

    return p1, p2


def test_example():
    with open(Path(__file__).parent / "example") as fp:
        p1, p2 = solve(fp)

    assert p1 == 13
    assert p2 == 43


def main():
    with open(0) as fp:
        p1, p2 = solve(fp)

    print(f"Part 1: {p1}")
    print(f"Part 2: {p2}")


if __name__ == "__main__":
    main()
