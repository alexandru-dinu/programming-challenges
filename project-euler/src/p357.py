#!/usr/bin/env python
# coding: utf-8

# In[ ]:


import multiprocessing as mp
import pickle

import numpy as np
from sympy import divisor_count, divisors, sieve
from tqdm import tqdm

# In[ ]:


N = 1e8

try:
    prime_set = pickle.load(open("data/prime_set_1e8.pkl", "rb"))
except FileNotFoundError:
    sieve._reset()
    sieve.extend(N)
    prime_set = set(sieve._list)

is_prime = lambda x: x in prime_set


# In[ ]:


def compute(n):
    ds = divisors(n, generator=True)
    l = divisor_count(n)

    if l % 2 == 1:
        return False

    for i in range(l // 2):
        d = next(ds)
        if not is_prime(d + n // d):
            return False

    return True


def do_batched(batch):
    s = 0
    for n in tqdm(batch):
        if compute(n):
            s += n
    return s


# In[ ]:


batches = np.arange(N, dtype=int).reshape(100, -1).tolist()

pool = mp.Pool(processes=6)
out = pool.map(do_batched, batches)

sum(out)
