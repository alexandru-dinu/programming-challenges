from functools import reduce
from operator import xor

input()
xs = list(map(int, input().strip().split()))
print(reduce(xor, xs) ^ reduce(xor, range(1, len(xs) + 2)))
