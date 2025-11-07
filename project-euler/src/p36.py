#!/usr/bin/env python
# coding: utf-8


def is_palindrome(n):
    x1 = str(n)
    x2 = bin(n)[2:]
    return (x1 == x1[::-1]) and (x2 == x2[::-1])


N = 1e6
s = [n for n in range(int(N)) if is_palindrome(n)]
print(sum(s))
