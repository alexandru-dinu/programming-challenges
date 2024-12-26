#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long

void solve(int tc)
{
    int n;
    cin >> n;

    if (n < 4) {
        cout << "-1\n";
        return;
    }

    if (n == 4) {
        cout << "3 1 4 2\n";
        return;
    }

    if (n == 5) {
        cout << "4 2 5 1 3\n";
        return;
    }

    int lo = n - (n % 2 == 1);
    int hi = n - (n % 2 == 0);

    for (int i = lo; i > 4; i -= 2)
        cout << i << " ";

    cout << "4 2 5 1 3 ";

    for (int i = 7; i <= hi; i += 2)
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
