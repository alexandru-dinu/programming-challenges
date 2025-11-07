#!/usr/bin/env python
# coding: utf-8

# 70 coloured balls are placed in an urn, 10 for each of the seven rainbow colours.
#
# What is the expected number of distinct colours in 20 randomly picked balls?

# In[ ]:


from collections import Counter

import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns
from tqdm import trange

get_ipython().run_line_magic("matplotlib", "inline")
get_ipython().run_line_magic("config", "InlineBackend.figure_format = 'retina'")
sns.set()


# In[ ]:


balls = []
for c in range(7):
    balls.extend([c] * 10)
balls = np.array(balls)

cnt = Counter()
N = 1_000_000

for _ in trange(N):
    idx = np.random.permutation(len(balls))
    u = len(np.unique(balls[idx[:20]]))
    cnt[u] += 1 / N


# In[ ]:


plt.stem(*zip(*cnt.items()), linefmt="C0--")


# In[ ]:


x, f = map(np.array, zip(*cnt.items()))
np.dot(x, f)


# In[ ]:


# In[ ]:
