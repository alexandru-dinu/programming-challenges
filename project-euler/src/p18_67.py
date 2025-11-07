#!/usr/bin/env python
# coding: utf-8

# In[ ]:


import re

import numpy as np

# In[ ]:


def solve(T):
    # bottom-up max reduce

    r, _ = T.shape

    for _ in range(r - 1):
        k = -2

        for i in range(len(T[k]) - 1):
            T[k, i] = max(T[k, i] + T[k + 1, i : i + 2])

        T = T[:-1, :-1]

    return T.item()


# ## P18

# In[ ]:


r = 15
T = np.zeros((r, r), dtype=np.uint32)
T[np.tril_indices(r)] = [
    75,
    95,
    64,
    17,
    47,
    82,
    18,
    35,
    87,
    10,
    20,
    4,
    82,
    47,
    65,
    19,
    1,
    23,
    75,
    3,
    34,
    88,
    2,
    77,
    73,
    7,
    63,
    67,
    99,
    65,
    4,
    28,
    6,
    16,
    70,
    92,
    41,
    41,
    26,
    56,
    83,
    40,
    80,
    70,
    33,
    41,
    48,
    72,
    33,
    47,
    32,
    37,
    16,
    94,
    29,
    53,
    71,
    44,
    65,
    25,
    43,
    91,
    52,
    97,
    51,
    14,
    70,
    11,
    33,
    28,
    77,
    73,
    17,
    78,
    39,
    68,
    17,
    57,
    91,
    71,
    52,
    38,
    17,
    14,
    91,
    43,
    58,
    50,
    27,
    29,
    48,
    63,
    66,
    4,
    68,
    89,
    53,
    67,
    30,
    73,
    16,
    69,
    87,
    40,
    31,
    4,
    62,
    98,
    27,
    23,
    9,
    70,
    98,
    73,
    93,
    38,
    53,
    60,
    4,
    23,
]

solve(T)


# ## P67

# In[ ]:


r = 100
T = np.zeros((r, r), dtype=np.uint32)
T[np.tril_indices(r)] = [
    int(x) for x in re.sub(r"[^0-9]", " ", open("data/p067_triangle.txt").read()).split()
]

solve(T)
