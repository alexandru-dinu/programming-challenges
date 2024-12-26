import functools as func

# 	Newton's method for fn(x) = x^2 - n


def isqrt(n):
    x = n
    y = (x + 1) // 2

    while y < x:
        x = y
        y = (x + n // x) // 2

    return x * x == n


with open("data/words.txt") as infile:
    count = 0

    words = infile.readline().split(",")

    for word in words:
        s = func.reduce(
            lambda x, y: x + y, list(map(lambda w: ord(w) - 64, word[1:-1])), 0
        )

        if isqrt(8 * s + 1):
            count += 1

    print(count)
