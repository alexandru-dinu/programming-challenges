from math import prod

from sympy import primerange

L = 50e6
space_a = sorted(primerange(2, int(L ** (1 / 2))))
space_b = sorted(primerange(2, int(L ** (1 / 3))))
space_c = sorted(primerange(2, int(L ** (1 / 4))))
size = prod(map(len, (space_a, space_b, space_c)))
print(f"space size: {size:,d}")

res = set()
tot = 0

for a in space_a:
    for b in space_b:
        for c in space_c:
            if (s := a**2 + b**3 + c**4) >= L:
                break
            else:
                tot += 1
                res.add(s)

print(len(res))
print(f"total checked: {tot:,d} ({100*tot/size:.2f}%)")
