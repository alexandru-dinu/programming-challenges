#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long

void solve()
{
    ll n;
    cin >> n;

    while (n != 1) {
        cout << n << " ";
        n = (n % 2 == 0) ? (n / 2) : (3 * n + 1);
    }
    cout << n << "\n";

    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    solve();

    return 0;
}
