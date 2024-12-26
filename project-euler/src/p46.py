"""
2k+1 = p + 2s

find smallest odd o (o = 2k+1) s.t. it DNE p, s: o = p + 2s

naive:
	for each o >= 9:
		find (p, s) s.t. p + 2s = o
		when found, return o

find largest p < o
let k = o - p
if (k/2 is a perfect square)
	=> (p, s)
else
	find p' closest to p
	p = p'


find first o s.t.
(o - p) / 2 is not a perfect square

G.C.: every even integer > 2 is the sum of 2 primes
o - p is even => o - p = p1 + p2

o := p + p1 + p2

find first o s.t.
(o-p) = 2*s^2
is not true anymore

2*s^2 = p1 + p2


#####
s = p1 + p2

o = p + 2p1 + 2p2
"""

from sympy import sieve
from math import sqrt, floor


def is_prime(x):
    (a, b) = sieve.search(x)
    return a == b


def largest_prime_less_than(n):
    if n == 3:
        return 2

    if is_prime(n):
        n -= 2

    primes = [False] * (n + 1)
    primes[2:] = [True] * (n - 1)

    p = -1
    for i in range(2, n + 1):
        if primes[i]:
            p = i
            for j in range(i + i, n + 1, i):
                primes[j] = False
    return p


def gen_plt(n):
    p = n
    prev = -1
    l = []
    while True:
        p = largest_prime_less_than(p)
        if p == prev:
            break
        l.append(p)

    return l


def solve():
    o = 9

    while True:
        if is_prime(o):
            o += 2
            continue

        plt = gen_plt(o)
        ks = list(map(lambda p: sqrt((o - p) / 2), plt))
        ks = list(map(lambda p: floor(p) != p, ks))

        if all(ks):
            print("Found o = {}".format(o))
            return o

        o += 2


if __name__ == "__main__":
    solve()
