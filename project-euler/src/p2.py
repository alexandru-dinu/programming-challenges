def fib(n):
    f1 = 1
    f2 = 2
    s = 2
    while f2 < n:
        nxt = f1 + f2
        f1 = f2
        f2 = nxt
        if nxt & 1 == 0:
            s += nxt
    return s


print(fib(4000000))
