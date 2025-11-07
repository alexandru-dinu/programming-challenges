#!/usr/bin/env python
# coding: utf-8

# - $15b, 6r$, probability of $bb$ is $P(bb) = \frac{15}{21} \cdot \frac{14}{20} = \frac{1}{2}$
#
# - The next such arrangement, for which there is exactly $\frac{1}{2}$ chance of taking $bb$, is: $85b, 35r$
#
# - **By finding the first arrangement to contain $n = b + r \geq 10^{12}$ discs in total, determine $b$**

# $$
# \begin{align}
# \frac{b}{n} \cdot \frac{b-1}{n-1} &= \frac{1}{2} \\
# 2b^2 - 2b - n^2 + n &= 0
# \end{align}
# $$
#
# Using this [QDE solver](https://www.alpertron.com.ar/QUAD.HTM), we obtain:
#
# $$
# \begin{align}
# b_{k+1} &= 3b_k + 2n_k - 2 \\
# n_{k+1} &= 4b_k + 3n_k - 3
# \end{align}
# $$

# In[ ]:


b, n, N = 15, 21, 1e12

while n < N:
    b_ = 3 * b + 2 * n - 2
    n_ = 4 * b + 3 * n - 3
    b, n = b_, n_

b
