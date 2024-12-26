#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long

bool is_prime(ll x)
{
    if (x <= 1)
        return false;
    if (x == 2 or x == 3 or x == 5 or x == 7)
        return true;
    if (x % 2 == 0 or x % 3 == 0 or x % 5 == 0 or x % 7 == 0)
        return false;

    for (int i = 2; i * i <= x; i++)
        if (x % i == 0)
            return false;

    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int n;
    cin >> n;

    while (n--) {
        ll x;
        cin >> x;

        // a t-prime can be only a square number whose root is a prime
        ll r = sqrt(x);
        cout << (((r * r == x) and is_prime(r)) ? "YES" : "NO") << "\n";
    }

    return 0;
}
