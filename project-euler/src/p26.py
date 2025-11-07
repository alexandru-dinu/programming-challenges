#!/usr/bin/env python
# coding: utf-8

# In[ ]:


class divide:
    def __init__(self, x, y):
        self.x, self.y = x, y
        self.i, self.nr, self.r = self.__div(x, y)

    def __str__(self):
        nr_ = "" if not self.nr else "".join(map(str, self.nr))
        r_ = "" if not self.r else "".join(map(str, self.r))

        cases = {(1, 1): f".{nr_}({r_})", (1, 0): f".{nr_}", (0, 1): f".({r_})", (0, 0): f""}

        lhs = f"{self.x}/{self.y}"
        rhs = f'{self.i}{cases[nr_ != "", r_ != ""]}'

        return f"{lhs} = {rhs}"

    def __repr__(self):
        return str(self)

    @staticmethod
    def __div(x, y):
        assert y != 0

        i, r = x // y, x % y

        seen, digits = {r: 0}, []

        while True:
            r *= 10
            digits += [r // y]
            r %= y

            if r in seen:
                loc = seen[r]

                if digits[loc:] == [0]:
                    digits[loc:] = []

                # integral, non-rep, rep
                return i, digits[:loc], digits[loc:]

            seen[r] = len(digits)


# In[ ]:


N, maxr, maxd = 1000, -1, None

for n in range(1, N + 1):
    d = divide(1, n)
    if len(d.r) > maxr:
        maxr = len(d.r)
        maxd = d.y

maxd
