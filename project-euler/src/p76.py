N = 100

dp = {}

"""
dp[n,k] = target n with parts <= k
use k ==> dp[n-k,k]         # reduce target, I can still use k
don't use k ==> dp[n,k-1]   # same target, reduce max part I can use
dp[n,k>n] = dp[n,n]
"""

# base case 1: can't get n with parts <= 0
for n in range(1, N + 1):
    dp[n, 0] = 0
# base case 2: only 1 way to get 0 with any parts
for k in range(N):
    dp[0, k] = 1

for n in range(1, N + 1):
    for k in range(1, n + 1):
        dp[n, k] = dp[n - k, min(k, n - k)] + dp[n, k - 1]

print(dp[N, N - 1])
