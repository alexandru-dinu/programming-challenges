#!/usr/bin/env python
# coding: utf-8

# In[ ]:


from itertools import permutations

x = "0123456789"
p = permutations(x)
N = int(1e6)
"".join([next(p) for _ in range(N)][-1])
