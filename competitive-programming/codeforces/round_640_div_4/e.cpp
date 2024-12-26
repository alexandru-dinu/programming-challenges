#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long

void solve(int tc)
{
    int n;
    cin >> n;

    vector<int> xs(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> xs[i];

    vector<int> pre(n + 1, 0);
    for (int i = 1; i < n + 1; ++i)
        pre[i] = pre[i - 1] + xs[i - 1];

    unordered_map<int, int> m;
    for (int i = 0; i < n; ++i)
        ++m[xs[i]];

    unordered_set<int> found;

    int ans = 0;

    for (int i = 1; i < n + 1; ++i) {
        for (int j = 0; j < i - 1; ++j) {
            int cur = pre[i] - pre[j];

            if (m.find(cur) != m.end() && found.find(cur) == found.end()) {
                ans += m[cur];
                found.insert(cur);
            }
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int tc;

    // tc = 1;
    cin >> tc;

    while (tc--) {
        solve(tc);
    }

    return 0;
}
