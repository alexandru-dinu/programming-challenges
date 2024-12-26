"""
Task 2: RECT
https://github.com/ranaldmiao/sg_noi_archive/blob/master/2005/statements/main.pdf
"""

import sys
from dataclasses import dataclass
from itertools import combinations
from typing import List


@dataclass
class OriginRectangle:
    """Origin-aligned rectangle.

    Translations are "ignored" by essentially fixing the rectangle to the origin.
    """

    w: float
    h: float

    def rot90(self) -> "OriginRectangle":
        """Perform a ccw 90-degree rotation using matrix R = [0, -1; 1, 0].

        Since we disregard translations, the effect of the rotation is to
        swap the width and height.
        """
        return OriginRectangle(w=self.h, h=self.w)


def iterate(f, x):
    """Compute [x, f(x), f(f(x)), ...]"""
    yield x
    yield from iterate(f, f(x))


def is_inside(r1: OriginRectangle, r2: OriginRectangle) -> bool:
    """Returns True iff r1 is inside of r2."""
    return r1.w <= r2.w and r1.h <= r2.h


def are_comparable(r1: OriginRectangle, r2: OriginRectangle) -> bool:
    """Returns True iff r1 and r2 are comparable via a rotation."""
    for a in [r1, r1.rot90()]:
        for b in [r2, r2.rot90()]:
            if is_inside(a, b) or is_inside(b, a):
                return True


def solve(rs: List[OriginRectangle]) -> int:
    res = 0

    for r1, r2 in combinations(rs, 2):
        res += not are_comparable(r1, r2)

    return res


def main():
    rs = []

    with open(sys.argv[1]) as fp:
        _, *lines = fp.readlines()

        for line in lines:
            x1, y1, x2, y2 = map(float, line.strip().split())
            rs.append(OriginRectangle(w=abs(x1 - x2), h=abs(y1 - y2)))

    print(solve(rs))


if __name__ == "__main__":
    main()
