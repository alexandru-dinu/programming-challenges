#!/usr/bin/env python
# coding: utf-8

# - The series, $1^1 + 2^2 + 3^3 + ... + 10^{10} = 10405071317$.
# - Find the last ten digits of the series, $1^1 + 2^2 + 3^3 + ... + 1000^{1000}$.
# - That is, $\sum_{n=1}^{1000} n^n \bmod 10^{10}$

# In[ ]:


N, mod = 1000, int(1e10)
sum([pow(x, x, mod) for x in range(1, N + 1)]) % mod
