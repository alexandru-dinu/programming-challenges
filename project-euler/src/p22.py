#!/usr/bin/env python
# coding: utf-8

# In[ ]:


import string

# In[ ]:


names = open("data/p022_names.txt").read().strip().replace('"', "").split(",")
names = sorted(names)

n2i = {name.lower(): i + 1 for (i, name) in enumerate(names)}
a2i = {a: i + 1 for (i, a) in enumerate(string.ascii_lowercase)}

score = lambda name: n2i[name] * sum([a2i[c] for c in name])

sum([score(name) for name in n2i])
