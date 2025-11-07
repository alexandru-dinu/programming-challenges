#!/usr/bin/env python
# coding: utf-8

# ## Statement
#
# $P(\text{score}|\text{dist}=x) = 1 - \dfrac{x}{q}, \ q > 50$
#
# - during each practice run, shoot from distances $x =\overline{1 \dots 50}$
# - precisely $2 \%$ chance to score a total of exactly $20$ points
# - **find $q$, rounded to $10$ decimal places**
#
# ## Solution
# The underlying distribution counting $k$ successes from $n$ trials, where the trials are not necessarily identically distributed, is the [Poisson binomial distribution](https://en.wikipedia.org/wiki/Poisson_binomial_distribution).
#
# However, computing $\Pr(K=20)$ using the pmf is infeasible.
#
# ### Dynamic programming
# Let $P_n(k)$ denote the probability of obtaining $k$ successes in $n$ trials:
# - $P_1(0) = 1-p_1$
# - $P_1(1) = p_1$
# - $P_n(0) = P_{n-1}(0) \cdot (1-p_n)$ (only failures in all trials)
# - $P_n(n) = P_{n-1}(n-1) \cdot p_n$ (only successes in all trials)
#
# The general formula is:
# $P_n(k) = P_{n-1}(k-1) \cdot p_n + P_{n-1}(k) \cdot (1 - p_n)$
#
# That is, there are two cases:
# - get $k-1$ successes in the last $n-1$ trials, and get a final success $p_n$
# - get $k$ successes in the last $n-1$ trials, and get a final failure $(1 - p_n)$
#
# In our case: $p_x = 1-\dfrac{x}{q}$ and $P_{50}(20) = 0.02$.
#
# ## References
# - https://stats.stackexchange.com/questions/177199/success-of-bernoulli-trials-with-different-probabilities
# - http://csg.sph.umich.edu/abecasis/class/2006/615.05.pdf

# In[ ]:


import numpy as np
from sympy import *

# In[ ]:


q = symbols("q")
p = lambda x: 1 - x / q

n = 50  # trials
k = 20  # successes

P = [[0 for _ in range(n + 1)] for _ in range(n + 1)]

P[1][0] = 1 - p(1)
P[1][1] = p(1)

for cur_n in range(2, n + 1):
    P[cur_n][0] = P[cur_n - 1][0] * (1 - p(cur_n))

for cur_n in range(2, n + 1):
    P[cur_n][cur_n] = P[cur_n - 1][cur_n - 1] * p(cur_n)

for cur_n in range(2, n + 1):
    for cur_k in range(1, min(k + 1, cur_n + 1)):
        P[cur_n][cur_k] = expand(
            P[cur_n - 1][cur_k - 1] * p(cur_n) + P[cur_n - 1][cur_k] * (1 - p(cur_n))
        )


# In[ ]:


eq = lambda val: P[n][k].evalf(subs={q: val})


# In[ ]:


# q is between these 2:
lo = 50
hi = 53
target = 0.02  # P[n][k] must equal this

steps = 0
precision = 1e-16

while not np.isclose(lo - hi, 0, rtol=0, atol=precision):
    steps += 1
    mid = lo + (hi - lo) / 2
    val = float(eq(mid))

    if np.isclose(val, target, rtol=0, atol=precision):
        print(f"{val=}")
        print(f"{round(mid, 10)=}")
        print(f"{steps=}")
        break

    elif val > 0.02:
        lo = mid  # + delta

    elif val < 0.02:
        hi = mid  # - delta

    else:
        assert False, "unreachable"


# In[ ]:
