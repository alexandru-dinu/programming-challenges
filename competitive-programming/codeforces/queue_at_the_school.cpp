#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n, t;
    string v;
    cin >> n >> t >> v;

    while (t--) {
        for (int i = 0; i < n - 1; ++i) {
            if (v[i] == 'B' and v[i + 1] == 'G') {
                v[i] ^= v[i + 1];
                v[i + 1] ^= v[i];
                v[i] ^= v[i + 1];
                i++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << v[i];
    }

    return 0;
}
