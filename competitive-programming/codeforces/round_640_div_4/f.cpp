#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long

/*
 * general formula: n0 | n2 | n1
 */

void solve(int tc)
{
    int n0, n1, n2;
    cin >> n0 >> n1 >> n2;

    if (n0 > 0)
        for (int i = 0; i <= n0; ++i)
            cout << 0;

    if (n2 > 0) {
        for (int i = 0; i <= n2; ++i)
            cout << 1;
    }

    // already put a 01
    if (n0 > 0 && n2 > 0)
        --n1;

    if (n1 > 0) {
        // start with 0 iff previously put 1s
        int c = (n2 > 0) ? 0 : 1;

        // already have a 0/1 char
        int adjust = (n0 > 0 || n2 > 0);

        for (int i = adjust; i <= n1; ++i) {
            cout << c;
            c = 1 - c;
        }
    }

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
