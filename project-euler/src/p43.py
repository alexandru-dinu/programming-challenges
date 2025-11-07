#!/usr/bin/env python
# coding: utf-8

# 0 to 9 pandigital number (e.g. $1406357289$)
#
# $
# \begin{align}
# d_2 d_3 d_4=406 \ &\vdots \ 2 \\
# d_3 d_4 d_5=063 \ &\vdots \ 3 \\
# d_4 d_5 d_6=635 \ &\vdots \ 5 \\
# d_5 d_6 d_7=357 \ &\vdots \ 7 \\
# d_6 d_7 d_8=572 \ &\vdots \ 11 \\
# d_7 d_8 d_9=728 \ &\vdots \ 13 \\
# d_8 d_9 d_{10}=289 \ &\vdots \ 17
# \end{align}
# $
#
# find the sum of all 0 to 9 pandigital numbers with this property

# In[ ]:


get_ipython().run_cell_magic(
    "time",
    "",
    "\nfrom itertools import permutations\n\nnums = []\n\nfor d in permutations(range(10)):\n    if d[0] == 0: continue\n    if d[5] not in {0, 5}: continue\n    if d[3] not in {0, 2, 4, 6, 8}: continue\n    if (d[2]*100 + d[3]*10 + d[4]) %  3 > 0: continue\n    if (d[4]*100 + d[5]*10 + d[6]) %  7 > 0: continue\n    if (d[5]*100 + d[6]*10 + d[7]) % 11 > 0: continue\n    if (d[6]*100 + d[7]*10 + d[8]) % 13 > 0: continue\n    if (d[7]*100 + d[8]*10 + d[9]) % 17 > 0: continue\n\n    nums += [int(''.join(map(str, d)))]\n\nprint(nums)\nprint(f'sum: {sum(nums)}')\n",
)
