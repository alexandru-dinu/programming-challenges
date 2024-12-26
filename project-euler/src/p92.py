import sys
from functools import reduce
from itertools import islice, accumulate, repeat, takewhile


def digits(n):
    d = []
    while n:
        d.append(n % 10)
        n = n // 10
    return d


def next_from(n):
    return reduce(lambda x, y: x + y * y, digits(n), 0)


def iterate(f, x):
    return accumulate(repeat(x), lambda fx, _: f(fx))


def take(n, it):
    return [x for x in islice(it, n)]


def run(n):
    return takewhile(lambda x: x != 1 and x != 89, iterate(next_from, n))


def terminates(n, mem):
    chain = iterate(next_from, n)
    path = [n]
    while True:
        if n in mem:
            return mem[n]

        n = next(chain)
        path.append(n)

        if n == 1:
            for p in path:
                mem[p] = 1
            return 1
        if n == 89:
            for p in path:
                mem[p] = 89
            return 89


def count(limit):
    mem = {}
    count = 0
    for i in range(1, limit):
        count += int(terminates(i, mem) == 89)

    return count


print(count(int(sys.argv[1])))
