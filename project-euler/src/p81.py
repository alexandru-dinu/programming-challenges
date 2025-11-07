#!/usr/bin/env python
# coding: utf-8

# In[ ]:


import numpy as np

# $M_{ij}^* \leftarrow M_{ij} + \min \left\{ M_{i+1,j}^*, M_{i,j+1}^* \right\}$

# In[ ]:


M = np.array(
    [
        131,
        673,
        234,
        103,
        18,
        201,
        96,
        342,
        965,
        150,
        630,
        803,
        746,
        422,
        111,
        537,
        699,
        497,
        121,
        956,
        805,
        732,
        524,
        37,
        331,
    ]
).reshape(5, 5)

M = np.array(
    [list(map(int, r.strip().split(","))) for r in open("data/p081_matrix.txt").readlines()]
)

n = len(M)

# costs for last row: cumulative sum from n-1 -> 0
M[n - 1, :] = M[n - 1, :][::-1].cumsum()[::-1]

# costs for last column: cumulative sum from n-1 -> 0
M[:, n - 1] = M[:, n - 1][::-1].cumsum()[::-1]

for i in range(n - 2, -1, -1):
    for j in range(n - 2, -1, -1):
        # M[i+1, j] and M[i, j+1] already contain the min cost
        M[i, j] += min(M[i + 1, j], M[i, j + 1])

print(f"total cost: {M[0,0]}")
