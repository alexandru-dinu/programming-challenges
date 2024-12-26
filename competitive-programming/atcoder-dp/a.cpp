#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long

// Frog (1)

void solve()
{
    int n;
    cin >> n;

    vector<int> hs(n);
    for (int i = 0; i < n; ++i)
        cin >> hs[i];

    // dp[i] = min cost to reach stone i
    vector<int> dp(n, 1e9);
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j : { i + 1, i + 2 }) {
            if (j >= n)
                break;

            // best cost to reach j is the min between
            // cost so far: dp[j]
            // best cost to reach i + cost to take the jump between i -> j
            dp[j] = min(dp[j], dp[i] + abs(hs[j] - hs[i]));
        }
    }

    cout << dp[n - 1] << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    solve();

    return 0;
}
