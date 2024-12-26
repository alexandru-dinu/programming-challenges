#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long

// Frog (2)
// generalization of problem A (where K = 2)

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> hs(n);
    for (int i = 0; i < n; ++i)
        cin >> hs[i];

    // dp[i] = min cost to reach stone i
    vector<int> dp(n, 1e9);
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
        for (int j = 1; j <= k; ++j) {
            if (i + j >= n)
                break;

            dp[i + j] = min(dp[i + j], dp[i] + abs(hs[i + j] - hs[i]));
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
