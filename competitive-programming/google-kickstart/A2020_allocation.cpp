#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long

void solve(int t)
{
    int n, b;
    cin >> n >> b;

    vector<int> hs(n);
    for (int i = 0; i < n; ++i)
        cin >> hs[i];

    sort(begin(hs), end(hs));

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (b - hs[i] < 0)
            break;

        ans++;
        b -= hs[i];
    }

    cout << "Case #" << t << ": " << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i)
        solve(i);

    return 0;
}
