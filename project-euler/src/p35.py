from sympy import sieve
from itertools import permutations
from functools import reduce
from threading import Thread
import queue

Sieve = [2] + list(sieve.primerange(1, 1000000))

i = 2
prime = {}
for p in Sieve:
    while i < p:
        prime[i] = False
        i += 1

    prime[p] = True
    i = p + 1

for i in range(Sieve[-1] + 1, 1000001):
    prime[i] = False


evens = set(["0", "2", "4", "6", "8"])


def rotate_all(l):
    s = []
    for i in range(len(l)):
        s.append(l[-i:] + l[:-i])
    return s


def count(lb, ub, q):
    lb, ub = int(lb), int(ub)
    s = 1  # account for 2

    print("Searching {} -> {}".format(lb, ub))

    for x in range(lb, ub):
        if x & 1 == 0:
            continue

        digits = [x for x in str(x)]

        if evens.intersection(set(digits)) != set():
            continue

        perms = map(lambda n: int("".join(n)), rotate_all(digits))
        perms_prime = list(map(lambda n: prime[n], perms))

        if all(perms_prime):
            s += 1

    print("Found {}".format(s))


count(3, 1000000, None)
