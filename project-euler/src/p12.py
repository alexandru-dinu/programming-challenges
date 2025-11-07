#!/usr/bin/env python
# coding: utf-8

# In[ ]:


from sympy import divisors

# In[ ]:


def gen():
    l = 1
    while True:
        n = sum(range(1, l + 1))
        d = len(divisors(n))
        yield n, d
        l += 1


g = gen()

while True:
    n, d = next(g)
    if d > 500:
        print(n)
        break
