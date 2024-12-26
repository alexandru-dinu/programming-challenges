"""
T[i,j] = best cost for Ai..Aj

T[i,j] = min_k {
    T[i,k] + T[k+1,j] +                        // sub-problems
    mats[i].rows * mats[k].cols * mats[j].cols // cost of '[i..k] * A[k+1..j]
}

complexity: upper triu (n) => n^2, for each -> iter k => n^3
"""

from collections import namedtuple

import numpy as np

dims = namedtuple("dims", ["rows", "cols"])

mats = [
    dims(2, 3),
    dims(3, 6),
    dims(6, 4),
    dims(4, 5),
]

n = len(mats)

T = np.infty * np.ones((n, n))

# T[i,i] = 0 // base-case, 1 matrix
np.fill_diagonal(T, 0)

# S[i,j] = k: best way to multiply i->j is to go through k
S = np.infty * np.ones((n, n))

# iterate through every upper diagonal
for gap in range(1, n):
    for i in range(n - gap):
        j = i + gap

        for k in range(i, j):
            cost = T[i, k] + T[k + 1, j] + mats[i].rows * mats[k].cols * mats[j].cols

            # update if the cost of going through k is smaller than previously known
            if cost < T[i, j]:
                T[i, j] = cost
                S[i, j] = k

print(T)
print("-" * 32)
print(S)
