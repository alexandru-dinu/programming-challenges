#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long
#define sol_t void

sol_t solve(int tc)
{
    ll l, r;
    cin >> l >> r;

    int i = 1;
    while (i <= max(l, r)) {
        if (l >= r) {
            l -= i;
        } else {
            r -= i;
        }
        ++i;
    }

    printf("Case: #%d: %ld %ld %ld\n", tc, i - 1, l, r);
    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int tc;

    // tc = 1;
    cin >> tc;

    for (int t = 1; t <= tc; ++t) {
        solve(t);
    }

    return 0;
}
