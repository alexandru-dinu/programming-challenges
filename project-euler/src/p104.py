"""
L = log10(x)
floor(10 ** (L - (floor(L) + 1) + k)) gives the first k digits of x
floor(L) + 1 = num digits
10**L
----- * 10**k
10**n
"""

from math import floor, log10, sqrt

a = 1
b = 1
k = 2

phi = 0.5 * (1 + sqrt(5))
logphi = log10(phi)
c = log10(sqrt(5))
# psi = 0.5 * (1 - sqrt(5)) # vanishingly small as k increases
"""
Fk ~= phi**k / sqrt(5) for large enough k
L = log10(Fk) ~= k log10(phi) - log10(sqrt(5))
          ~= k logphi - c

10 ** (frac(k logphi - c) - 1 + 9)
"""


def frac(x):
    return x - floor(x)


def is_pandigital(x):
    assert x == int(x)
    return "".join(sorted(str(x))) == "123456789"


while True:
    (a, b, k) = (b, (a + b) % (10**9), k + 1)

    first = floor(10 ** (frac(k * logphi - c) - 1 + 9))

    if is_pandigital(first) and is_pandigital(b):
        print(k)
        break
