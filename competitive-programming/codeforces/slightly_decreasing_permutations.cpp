#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;

    if (k == 0) {
        for (int i = 1; i <= n; i++) {
            cout << i << " ";
        }
    } else {
        for (int i = k + 1; i >= 1; i--) {
            cout << i << " ";
        }
        for (int i = k + 2; i <= n; i++) {
            cout << i << " ";
        }
    }

    return 0;
}
