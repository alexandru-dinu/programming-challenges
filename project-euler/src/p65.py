#!/usr/bin/env python
# coding: utf-8

# In[ ]:


import operator
from fractions import Fraction
from functools import reduce

frac = lambda x: Fraction(x).limit_denominator(int(1e20))


# $\sqrt{2} = \left[1;(2)\right]$
#
# $\sqrt{23} = \left[4;(1,3,1,8)\right]$

# In[ ]:


class CFrac:
    def __init__(self, ini, rep):
        self.ini = ini
        self.rep = rep

    def iterate(self):
        out = []

        for i in range(1, len(self.rep) + 1):
            rep_ = self.rep[:i]

            f = 0
            for r in rep_[::-1]:
                f = 1 / (r + f)

            x = self.ini + f
            out += [(x, frac(x))]

        return list(zip(*out))


ini, rep = 2, [1, 2] + reduce(operator.add, [[1, 1, 4 + 2 * x] for x in range(33)])
# ini, rep = 1, [2] * 10

e, c = CFrac(ini, rep).iterate()

e[-1]
