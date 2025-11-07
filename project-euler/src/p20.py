#!/usr/bin/env python
# coding: utf-8

# In[ ]:


import operator
from functools import reduce

fact = lambda x: reduce(operator.mul, range(1, x + 1), 1)

sum(map(int, str(fact(100))))
