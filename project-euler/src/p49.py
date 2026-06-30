from sympy import primerange

# numbers are x, x + 18k, x + 36k
# with 1 <= k <= 249
# 18 b/c 2|t (even) and 9|t (after digit manipulation)


def are_perms(x1, x2, x3):
    return sorted(str(x1)) == sorted(str(x2)) == sorted(str(x3))


space = set(primerange(1000, 10_000))

for x1 in space:
    for k in range(1, 250):
        x2 = x1 + 18 * k
        x3 = x1 + 36 * k
        if x2 in space and x3 in space and are_perms(x1, x2, x3):
            print(x1, x2, x3, 18 * k)
