n = 600851475143
div = 2

while div * div < n:
    while n % div == 0:
        n = n / div
    div += 1

print(n)
