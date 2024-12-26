from math import sqrt


def factor(n):
    factors = set()
    for x in range(1, int(sqrt(n)) + 1):
        if n % x == 0:
            factors.add(x)
            factors.add(n // x)
    return sorted(factors)


def three_digits_factors(n):
    f = map(str, factor(n))
    tdf = filter(lambda x: len(x) == 3, f)
    itdf = map(int, tdf)

    return list(itdf)


def is_pal(x):
    sx = str(x)
    return sx == sx[::-1]


def solve():
    for i in range(998001, 10000, -1):
        if not is_pal(i):
            continue

        print("Trying {}".format(i))

        tdf = three_digits_factors(i)
        for f1 in tdf:
            f2 = i / f1
            if f2 in tdf:
                print("Found {} -> {}, {}".format(i, f1, f2))
                return


solve()
