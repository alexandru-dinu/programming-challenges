alpha = 1000000
beta = 2000


def get(N):
    for a in range(1, N + 1):
        for b in range(a + 1, N + 1):
            lhs = alpha + 2 * a * b
            rhs = beta * (a + b)

            if lhs == rhs:
                c = 1000 - a - b
                return a, b, c


a, b, c = get(1000)
print(str(a) + ", " + str(b) + ", " + str(c))
print(a * b * c)
