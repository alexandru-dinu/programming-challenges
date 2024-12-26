#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long

void better_solve()
{
    /*
     * there's this pattern:
     * 2^n + sum(2^1 ... 2^(n/2 - 1) - sum(2^n/2 ... 2^(n-1))
     */
    int n;
    cin >> n;

    int mid = n / 2;

    ll d = 1 << n;

    for (int i = 1; i < mid; i++)
        d += (1 << i);

    for (int i = mid; i < n; i++)
        d -= (1 << i);

    cout << d << "\n";
}

void solve()
{
    int n;
    cin >> n;

    ll d = 0;

    if (n == 2) {
        cout << 2 << "\n";
        return;
    }

    int l;

    if (n / 2 % 2 == 0)
        l = n / 2 + 1;
    else
        l = n / 2;

    d += 2 + pow(2, n);

    for (int i = 2; i < l; i++) {
        if (i % 2 == 0) {
            d -= pow(2, n - i + 1) + pow(2, n - i);
        } else {
            d += pow(2, i - 1) + pow(2, i);
        }
    }

    if (n / 2 % 2 != 0) {
        d += pow(2, n / 2 - 1) - pow(2, n / 2);
    }

    cout << abs(d) << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
        solve();
    // better_solve();

    return 0;
}
