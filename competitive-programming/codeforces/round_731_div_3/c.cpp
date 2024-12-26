#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long

/*
 * if it's possible to do an action -> do it
 */

void solve(int tc)
{
    int k, n, m;
    cin >> k >> n >> m;

    vector<int> as(n), bs(m);

    for (int i = 0; i < n; ++i)
        cin >> as[i];

    for (int i = 0; i < m; ++i)
        cin >> bs[i];

    vector<int> rs(n + m);
    int r = 0, i = 0, j = 0;

    while (r < n + m) {
        int old_r = r;

        // A can append
        while (i < as.size() && as[i] == 0) {
            ++k;
            rs[r++] = as[i++];
        }

        // B can append
        while (j < bs.size() && bs[j] == 0) {
            ++k;
            rs[r++] = bs[j++];
        }

        // A wants to change a line
        while (i < as.size() && 0 < as[i] && as[i] <= k) {
            rs[r++] = as[i++];
        }

        // B wants to change a line
        while (j < bs.size() && 0 < bs[j] && bs[j] <= k) {
            rs[r++] = bs[j++];
        }

        // no op could be performed
        if (r == old_r) {
            cout << "-1\n";
            return;
        }
    }

    for (auto i : rs)
        cout << i << " ";
    cout << "\n";
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
