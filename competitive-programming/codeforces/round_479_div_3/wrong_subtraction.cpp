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

    while (k--) {
        if (n % 10 == 0)
            n /= 10;
        else
            n--;
    }

    cout << n;

    return 0;
}
