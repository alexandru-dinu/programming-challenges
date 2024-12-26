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

    map<int, int> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ++m[x];
    }

    if (m[0] == 0) {
        cout << -1;
    } else {
        int t = m[5] - m[5] % 9;
        if (t == 0) {
            cout << 0;
        } else {
            for (int i = 0; i < t; i++) {
                cout << 5;
            }
            for (int i = 0; i < m[0]; i++) {
                cout << 0;
            }
        }
    }

    return 0;
}
