from typing import TextIO


def all_paths_memo_v1(G, src):
    """
    part1: `src` ~> out
    part2: `src` ~> fft ~> dac ~> out

    example of memo
    mem[node]:
        0: # paths to out
        1: # paths to out via dac
        2: # paths to out via fft
        3: # paths to out via dac & fft

    if we decompose:
        #(svr->fft) * #(fft->dac) * #(dac->out)
    we may explore beyond dst and reach out anyway
    """
    mem = {}

    def inner(cur):
        if cur in mem:
            return mem[cur]

        if cur == "out":
            return [1, 0, 0, 0]

        nxt = [0, 0, 0, 0]

        # traverse down
        for v in G.get(cur, []):
            res = inner(v)
            for i in range(4):
                nxt[i] += res[i]

        # update upon returning
        if cur == "dac":
            nxt[1] = nxt[0]
            nxt[3] += nxt[2]
        if cur == "fft":
            nxt[2] = nxt[0]
            nxt[3] += nxt[1]

        mem[cur] = nxt
        return nxt

    inner(src)
    return mem[src]


def all_paths_memo_v2(G, src):
    def cache(func):
        mem = {}

        def wrap(*args):
            if args in mem:
                print('get@', args, mem[args])
                return mem[args]
            mem[args] = func(*args)
            print('set@', args, mem[args])
            return mem[args]

        return wrap

    @cache
    def inner(cur, dac, fft):
        print(f"    {cur=}")
        if cur == "out" and dac and fft:
            return 1

        s = 0
        for v in G.get(cur, []):
            s += inner(v, dac | (v == "dac"), fft | (v == "fft"))

        print(f"<<< {cur=} | {dac=} | {fft=}; {s=}")
        return s

    return inner(src, False, False)


def solve(fp: TextIO):
    G = {}
    for g in fp.read().strip().split("\n"):
        u, vs = g.split(": ")
        G[u] = vs.split()

    p1 = all_paths_memo_v1(G, src="you")[0]
    p2 = all_paths_memo_v1(G, src="svr")[3]
    assert p2 == all_paths_memo_v2(G, src="svr")

    return p1, p2


def main():
    with open(0) as fp:
        p1, p2 = solve(fp)

    print(f"Part 1: {p1}")
    print(f"Part 2: {p2}")


if __name__ == "__main__":
    main()
