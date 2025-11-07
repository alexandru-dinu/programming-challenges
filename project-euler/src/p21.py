#!/usr/bin/env python
# coding: utf-8

# In[ ]:


from sympy import divisors

# sum of proper divisors, notation from the problem
d = lambda x: sum(divisors(x)[:-1])

s = []
for a in range(10000):
    if a != d(a) and d(d(a)) == a:
        s += [a]

sum(s)
