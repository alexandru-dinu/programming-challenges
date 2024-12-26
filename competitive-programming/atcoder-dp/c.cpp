#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long

// Vacation

void solve()
{
    int n;
    cin >> n;

    // dp[i] = max given that current activity ends with i (i = 0,1,2)
    vector<int> dp(3, 0);

    cin >> dp[0] >> dp[1] >> dp[2];

    for (int i = 1; i < n; ++i) {
        int x0, x1, x2;
        cin >> x0 >> x1 >> x2;

        // choose activity xi and max between last two different activites

        int m12 = max(dp[1], dp[2]);
        int m02 = max(dp[0], dp[2]);
        int m01 = max(dp[0], dp[1]);

        dp[0] = x0 + m12;
        dp[1] = x1 + m02;
        dp[2] = x2 + m01;
    }

    int res = max(dp[0], max(dp[1], dp[2]));
    cout << res << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    solve();

    return 0;
}
