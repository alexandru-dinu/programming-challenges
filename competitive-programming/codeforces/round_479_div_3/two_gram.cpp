#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long
#define sol_t void

sol_t solve(int tc)
{
    int n;
    cin >> n;

    string s;
    cin >> s;

    unordered_map<string, int> m;

    for (int i = 0; i < n - 1; i++)
        ++m[s.substr(i, 2)];

    auto best = max_element(begin(m), end(m), [](const auto &x, const auto &y) {
        return x.second < y.second;
    });

    cout << best->first << "\n";

    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int tc;

    tc = 1;
    // cin >> tc;

    while (tc--) {
        solve(tc);
    }

    return 0;
}
