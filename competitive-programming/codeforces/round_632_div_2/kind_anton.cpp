#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long

bool solve()
{
    int n;
    cin >> n;
    int a[n], b[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    if (b[0] != a[0])
        return false;

    if (b[0] == a[0] and n == 1)
        return true;

    int pos = (a[0] == 1);
    int neg = (a[0] == -1);

    for (int j = 1; j < n; j++) {
        int t = b[j] - a[j];

        if (t > 0 and pos == 0)
            return false;

        if (t < 0 and neg == 0)
            return false;

        pos |= (a[j] == 1);
        neg |= (a[j] == -1);
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        cout << (solve() ? "YES" : "NO") << "\n";
    }

    return 0;
}
