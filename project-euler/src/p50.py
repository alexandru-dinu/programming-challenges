#!/usr/bin/env python
# coding: utf-8

# - The prime 41, can be written as the sum of six consecutive primes:
# 41 = 2 + 3 + 5 + 7 + 11 + 13
#
# - This is the longest sum of consecutive primes that adds to a prime below one-hundred.
#
# - The longest sum of consecutive primes below one-thousand that adds to a prime,
# contains 21 terms, and is equal to 953.
#
# - **Which prime, below one-million, can be written as the sum of the most consecutive primes?**

# In[ ]:


import numpy as np
from sympy import sieve
from tqdm import tqdm

N = 1e6
sieve._reset()
sieve.extend(N)

primes = np.array(sieve._list)
prime_set = set(primes)
cs = np.cumsum(primes)

primes.shape


# $f(i,n) = \sum_{i}^{i+n}P_i$
#
# $S = \texttt{primes} < 1000000$
#
# $\exists \ i^*, n^*: f(i^*, n^*) \in S \wedge \not \exists \ i', n' > n^*: \ f(i', n') \in S$

# In[ ]:


d = -np.infty
p = None

for i in tqdm(range(len(primes))):
    for j in range(i, -1, -1):
        p_ = cs[i] - cs[j]
        if p_ > N:
            break

        if p_ in prime_set and (i - j) > d:
            d, p = i - j, p_
d, p
