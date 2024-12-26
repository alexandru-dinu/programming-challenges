#include <bits/stdc++.h>
#include <iostream>
#include <optional>

using namespace std;

#define ll long long
#define sol_t void

using entry_t = pair<optional<int>, optional<int>>;

sol_t solve(int tc)
{
    int n;
    cin >> n;

    vector<ll> v(n);
    set<ll> s;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        s.insert(v[i]);
    }

    unordered_map<ll, ll> g(n);
    ll first;

    for (ll x : v) {
        bool bu = false, bv = false;

        if (x % 3 == 0) {
            ll u = x / 3;
            if (s.find(u) != s.end()) {
                g[u] = x;
                bu = true;
            }
        }

        ll v = 2 * x;
        if (s.find(v) != s.end()) {
            g[v] = x;
            bv = true;
        }

        if (!bu and !bv)
            first = x;
    }

    stack<ll> ans;
    ans.push(first);
    for (int i = 0; i < n - 1; i++) {
        first = g[first];
        ans.push(first);
    }

    while (!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }

    cout << "\n";

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
