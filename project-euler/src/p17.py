#!/usr/bin/env python
# coding: utf-8

# In[ ]:


import re

import inflect

p = inflect.engine()

sum([len(re.sub(r"[^a-z]+", "", p.number_to_words(x))) for x in range(1, 1001)])
