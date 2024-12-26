#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int x, m[3][3];
    fill(m[0], m[3], 1);

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> x;
            if (x % 2 == 0)
                continue;

            m[i][j] = 1 - m[i][j];
            if (i >= 1)
                m[i - 1][j] = 1 - m[i - 1][j];
            if (i <= 1)
                m[i + 1][j] = 1 - m[i + 1][j];
            if (j >= 1)
                m[i][j - 1] = 1 - m[i][j - 1];
            if (j <= 1)
                m[i][j + 1] = 1 - m[i][j + 1];
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << m[i][j];
        }
        cout << "\n";
    }

    return 0;
}
