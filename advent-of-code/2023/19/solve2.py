import re
from pathlib import Path


def intersect(r1: range, r2: range):
    s = max(r1.start, r2.start)
    e = min(r1.stop, r2.stop)
    assert s < e
    return range(s, e)


def union(r1, r2):
    s = min(r1.start, r2.start)
    e = max(r1.stop, r2.stop)
    return range(s, e)


def range_reduce(xs, ys):
    if not xs:
        return ys

    res = []

    for x1, r1 in xs:
        for x2, r2 in ys:
            if x1 == x2:
                res.append((x1, union(r1, r2)))
                break
        else:
            res.append((x1, r1))

    return res


def make_tree(fp):
    rs, _ = fp.read().split("\n\n")
    rs = [r.strip() for r in rs.split("\n")]

    tree = {}

    for r in rs:
        src, checks = re.match("([a-z]+){(.*)}", r).groups()
        checks = checks.split(",")

        tree[src] = {}

        # keep track of opposite conditions as we continue with the conditions
        # (due to the order of pattern matching)
        opp = []

        # checks have a condition
        pattern = re.compile(r"([a-z]{1})(<|>)(\d+):([a-z]+|A|R)")
        for var, op, val, dst in map(lambda c: pattern.match(c).groups(), checks[:-1]):
            val = int(val)

            if op == ">":
                n = range(val + 1, 4001)
                op = range(1, val + 1)
            elif op == "<":
                n = range(1, val)
                op = range(val, 4001)

            # assert dst not in tree[src], dst
            if dst not in tree[src]:
                tree[src][dst] = [[*opp, (var, n)]]
            else:
                tree[src][dst].append([*opp, (var, n)])

            opp.append((var, op))

        # last check doesn't have an explicit condition, just the destination
        dst = checks[-1]
        assert re.match(r"[a-z]+|A|R", dst) is not None

        if dst not in tree[src]:
            tree[src][dst] = [opp.copy()]
        else:
            # need to extend (union) existing ranges for vars that exist
            tree[src][dst].append(opp)

    return tree


def traverse(tree):
    # find all var combinations for reaching acceptance states
    def inner(u, acc):
        if u == "R":
            return 0

        if u == "A":
            # res = {k: range(1, 4001) for k in "xmas"}
            # for x, r in acc:
            #     res[x] = intersect(res[x], r)
            # return math.prod(len(r) for r in res.values())
            print(acc)
            return 1

        s = 0
        for v, comb in tree[u].items():
            xs = acc + comb
            s += inner(v, xs)
        return s

    from rich import print

    print(tree)
    # return inner("in", [])


def test_example():
    with open(Path(__file__).parent / "example") as fp:
        assert traverse(make_tree(fp)) == 167409079868000


def main():
    with open(0) as fp:
        print(f"Part 2: {traverse(make_tree(fp))}")


if __name__ == "__main__":
    main()
