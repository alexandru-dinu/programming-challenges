#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long

void solve(int tc)
{
    ll n;
    int k;
    cin >> n >> k;

    if (k > n) {
        cout << "NO\n";
        return;
    }

    // n odd, k even
    if (n % 2 == 1 && k % 2 == 0) {
        cout << "NO\n";
        return;
    }

    // both odd or even
    else if (n % 2 == k % 2) {
        cout << "YES\n";
        for (int i = 1; i < k; ++i)
            cout << "1 ";
        cout << (n - k + 1) << "\n";
        return;
    }

    // n even, k odd
    else {
        int j = 1;
        int q = n - 2 * (k - j);
        if (q <= 0) {
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
        for (int i = 1; i < k; ++i)
            cout << "2 ";
        cout << q << "\n";
    }

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
