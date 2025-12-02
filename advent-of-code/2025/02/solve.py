from pathlib import Path
from typing import TextIO


def batched(xs, n):
    if not xs:
        return
    yield xs[:n]
    yield from batched(xs[n:], n)


def all_equal(xs):
    return all(map(lambda x: x == xs[0], xs[1:]))


def solve(fp: TextIO):
    xs = [tuple(map(int, x.split("-"))) for x in fp.read().strip().split(",")]

    print(max([x[1] - x[0] for x in xs]))

    p1 = 0
    for a, b in xs:
        for i in range(a, b + 1):
            s = str(i)
            n = len(s) // 2
            p1 += (s[:n] == s[n:]) * i

    p2 = 0
    for a, b in xs:
        for i in range(a, b + 1):
            s = str(i)
            n = len(s) // 2
            for p in range(1, n + 1):
                if all_equal(list(batched(s, p))):
                    p2 += i
                    break

    return p1, p2


def test_example():
    with open(Path(__file__).parent / "example") as fp:
        p1, p2 = solve(fp)

    assert p1 == 1227775554
    assert p2 == 4174379265


def main():
    with open(0) as fp:
        p1, p2 = solve(fp)

    print(f"Part 1: {p1}")
    print(f"Part 2: {p2}")


if __name__ == "__main__":
    main()
