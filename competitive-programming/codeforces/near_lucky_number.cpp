#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    ll n;
    int s = 0;
    cin >> n;

    while (n) {
        if (n % 10 == 4 or n % 10 == 7)
            s++;
        n /= 10;
    }

    cout << ((s == 4 or s == 7) ? "YES" : "NO");

    return 0;
}
