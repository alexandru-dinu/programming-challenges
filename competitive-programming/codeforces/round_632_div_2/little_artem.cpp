#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == n - 1 and j == m - 1)
                    cout << "W";
                else
                    cout << "B";
            }
            cout << "\n";
        }
    }

    return 0;
}
