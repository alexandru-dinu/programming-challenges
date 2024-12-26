#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long

void solve()
{
    int n;
    cin >> n;

    ll ans = 0;
    ll x;
    cin >> x;

    ll last = x;

    for (int i = 1; i < n; ++i) {
        cin >> x;

        if (x < last)
            ans += last - x;
        else
            last = x;
    }

    cout << ans << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    solve();

    return 0;
}
