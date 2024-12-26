#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long

#define MOD (1000000000 + 7)

/*
 * similar to the 'climbing stairs' problem
 * d[n] = ways of obtaining n (climbing to n-th stair)
 * by throwing 1..6 (1..6 step size)
 */

void solve()
{
    int n;
    cin >> n;

    vector<ll> d(n + 1, 0);
    d[0] = 1; // there is one way of obtaining value 0: do nothing

    for (int i = 1; i <= n; ++i)
        for (int k = 1; k <= min(i, 6); d[i] += d[i - k] % MOD, ++k)
            ;

    cout << d[n] % MOD;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    solve();

    return 0;
}
