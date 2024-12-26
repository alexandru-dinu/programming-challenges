#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int y;
    cin >> y;

    while (true) {
        y++;

        int a = y / 1000;
        int b = y / 100 % 10;
        int c = y / 10 % 10;
        int d = y % 10;

        if (a != b and a != c and a != d and b != c and b != d and c != d) {
            cout << y;
            break;
        }
    }

    return 0;
}
