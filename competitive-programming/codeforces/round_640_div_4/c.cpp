#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long
#define sol_t void

sol_t solve(int tc)
{
    ll n, k;
    cin >> n >> k;

    cout << k + (k - 1) / (n - 1) << "\n";

    return;
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
