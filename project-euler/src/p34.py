#!/usr/bin/env python
# coding: utf-8

# In[ ]:


from math import factorial as f
from math import log

from tqdm import tqdm

# In[ ]:


digits = lambda x: list(map(int, str(x)))
d = lambda n: np.ceil(log(n) / log(10)).astype(int)


def get_upper_bound():
    n = 9

    while True:
        s = sum(map(f, digits(n)))

        # if n is at least 1 order of magnitude larger than s,
        # there's no point searching further
        if d(n) > d(s):
            return (d(n) - 1) * f(9)

        n = n * 10 + 9


s, ub = 0, get_upper_bound()

for n in tqdm(range(10, ub)):
    if sum(map(f, digits(n))) == n:
        s += n

s
