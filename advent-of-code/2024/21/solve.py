import heapq
from collections import defaultdict
from pathlib import Path
from typing import TextIO

from bidict import bidict
from rich import print

NUMPAD = bidict(
    {
        0 + 0j: 7,
        0 + 1j: 8,
        0 + 2j: 9,
        1 + 0j: 4,
        1 + 1j: 5,
        1 + 2j: 6,
        2 + 0j: 1,
        2 + 1j: 2,
        2 + 2j: 3,
        3 + 0j: None,
        3 + 1j: 0,
        3 + 2j: "A",
    }
)
DIRPAD = bidict(
    {
        0 + 0j: None,
        0 + 1j: -1,  # ^
        0 + 2j: "A",
        1 + 0j: -1j,  # <
        1 + 1j: 1,  # v
        1 + 2j: 1j,  # >
    }
)
DIRS = bidict(
    {
        -1: "^",
        1: "v",
        -1j: "<",
        1j: ">",
        "A": "A",
    }
)
DEPTH2PAD = defaultdict(lambda: DIRPAD)
DEPTH2PAD[0] = NUMPAD


def to_plain_dict(d):
    if isinstance(d, defaultdict):
        return {k: to_plain_dict(v) for k, v in d.items()}
    return d


def dirs2str(dirs):
    return "".join(DIRS[d] for d in dirs)


def split(seq):
    cur = ""
    for x in seq:
        cur += x
        if x == "A":
            yield cur
            cur = ""


## State expander
def resolve_at_depth(code, d):
    def check_dirs(dirs, cur, pad):
        assert dirs[-1] == "A"
        for x in dirs[:-1]:
            cur += x
            if pad[cur] is None:
                return False
        return True

    code = [int(x) if x.isdigit() else DIRS.inverse[x] for x in code]
    pad = DEPTH2PAD[d]
    cur = pad.inverse["A"]

    for i, c in enumerate(code):
        nxt = pad.inverse[c]
        dh = nxt.real - cur.real
        dw = nxt.imag - cur.imag

        h_first = ([[1, -1][dh < 0]] * int(abs(dh))) + ([[1j, -1j][dw < 0]] * int(abs(dw))) + ["A"]
        w_first = ([[1j, -1j][dw < 0]] * int(abs(dw))) + ([[1, -1][dh < 0]] * int(abs(dh))) + ["A"]

        h_ok = check_dirs(h_first, cur, pad)
        w_ok = check_dirs(w_first, cur, pad)

        out = []
        if h_ok:
            out.append((i, dirs2str(h_first)))
            if h_first != w_first and w_ok:
                out.append((i, dirs2str(w_first)))
        else:
            assert w_ok
            out.append((i, dirs2str(w_first)))

        yield out

        cur = nxt

    assert pad[cur] == "A"


## Attempt 1
def state_space_search(code, maxdepth):
    mem = {}

    # state: (priority, code, depth, hierarchical parent index, current index at depth)
    frontier = []
    for seq in resolve_at_depth(code, 0):
        for i, nxt in seq:
            heapq.heappush(frontier, (0, nxt, 1, (), i))

    while frontier:
        _, cur, d, parent_index, current_index = heapq.heappop(frontier)

        chi = parent_index + (current_index,)

        state = (cur, d)
        if state in mem and mem[state] <= len(cur):
            continue

        # mem[state] should store the best len:
        mem[state] = len(cur)

        if d == maxdepth:
            continue

        for sub in split(cur):
            for seq in resolve_at_depth(sub, d):
                for i, nxt in seq:
                    heapq.heappush(frontier, (len(nxt), nxt, d + 1, chi, i))

    # paths = to_plain_dict(paths)
    # for k, v in sorted(paths[maxdepth].items()):
    #     print(f"{k}: {v} ({v})")

    return sum(paths[maxdepth].values())


## Attempt 2
def top_down(code, maxdepth):
    def mycache(func):
        mem = {}

        def inner(*args):
            if args not in mem:
                mem[args] = func(*args)
            return mem[args]

        return inner

    @mycache
    def _inner(seq, d):
        if d == maxdepth:
            return len(seq)

        tot = 0
        for cur in split(seq):
            # e.g. resolve_at_depth
            # vvvA: [
            #   [
            #       (0, 'v<A'), # nxt (one of)
            #       (0, '<vA'),
            #   ], # sub
            #   [
            #       (1, 'A')
            #   ],
            #   [
            #       (2, 'A')
            #   ],
            #   [
            #       (3, '^>A'),
            #       (3, '>^A'),
            #   ],
            # ]
            for sub in resolve_at_depth(cur, d):
                tot += min(_inner(nxt, d + 1) for _, nxt in sub)

        return tot

    return sum(min(_inner(nxt, 1) for _, nxt in seq) for seq in resolve_at_depth(code, 0))


def solve(fp: TextIO):
    codes = fp.read().strip().split("\n")

    # FUNC = state_space_search
    FUNC = top_down

    p1 = p2 = 0
    for code in codes:
        num = int(code[:-1])

        p1 += num * (r1 := FUNC(code, maxdepth=3))
        print(num, r1)

        p2 += num * (r2 := FUNC(code, maxdepth=26))
        print(num, r2)

    return p1, p2


def test_example():
    with open(Path(__file__).parent / "example") as fp:
        p1, p2 = solve(fp)

    assert p1 == 126384
    assert p2 == 154115708116294


def main():
    with open(0) as fp:
        p1, p2 = solve(fp)

    print(f"Part 1: {p1}")
    print(f"Part 2: {p2}")


if __name__ == "__main__":
    main()
