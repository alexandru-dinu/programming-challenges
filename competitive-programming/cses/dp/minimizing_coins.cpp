#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long

#define INF (1000000000 + 7)

void solve()
{
    int n, x;
    cin >> n >> x;

    vector<ll> coins(n);
    for (int i = 0; i < n; ++i)
        cin >> coins[i];

    // dp[x] = min. ways of producing value x
    // dp[x] = min_{c in coins} dp[x - c] + 1
    //         using each coin (c): 1 + min. ways of producing x - c (remainder)
    // dp[0] = 0
    vector<ll> dp(x + 1, INF);
    dp[0] = 0;

    for (int i = 1; i <= x; ++i) {
        for (auto c : coins) {
            if (i - c >= 0)
                dp[i] = min(dp[i], 1 + dp[i - c]);
        }
    }

    ll ans = (dp[x] == INF) ? (-1) : dp[x];
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    solve();

    return 0;
}
