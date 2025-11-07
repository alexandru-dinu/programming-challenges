#!/usr/bin/env python
# coding: utf-8

# In[ ]:


from sympy import sieve

sieve._reset()

N = 2e6
sieve.extend(N)
sum(sieve._list)
