#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = -n; i <= n; i++) {
        int c = n - abs(i);

        for (int j = 0; j < 2 * abs(i); j++)
            cout << " ";
        for (int j = 0; j < c; j++)
            cout << j << " ";
        for (int j = c; j > 0; j--)
            cout << j << " ";

        cout << 0 << endl;
    }

    return 0;
}
