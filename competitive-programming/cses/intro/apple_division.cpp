#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long

void solve()
{
    int n;
    cin >> n;
    vector<int> xs(n);

    for (int i = 0; i < n; ++i)
        cin >> xs[i];

    ll res = 1e11;

    for (ll i = 1; i < pow(2, n); ++i) {
        ll diff = 0;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1)
                diff += xs[j];
            else
                diff -= xs[j];
        }
        res = min(res, abs(diff));
    }

    cout << res << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    solve();

    return 0;
}
