#!/usr/bin/env python
# coding: utf-8

# In[ ]:


from itertools import permutations

from tqdm import tqdm

to_num = lambda x: int("".join(map(str, x)))

p_digits = permutations(range(1, 10))

idx, out = 5, set()

for _ in tqdm(range(362880)):
    p = next(p_digits)

    for i in range(1, idx):
        m1, m2, r = map(to_num, [p[:i], p[i:idx], p[idx:]])
        if m1 * m2 == r:
            out.add(r)

sum(out)
