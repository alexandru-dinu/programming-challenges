from itertools import permutations

for s in permutations("987654321"):
    s = "".join(s)
    for n in range(2, 9):
        for i in range(1, 9 // n + 1):
            x = int(s[:i])  # x * 1
            y = [str(x * j) for j in range(1, n + 1)]
            if s == "".join(y):
                print(y, s)
                exit(0)
