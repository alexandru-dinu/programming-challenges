#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long

// similar to https://codeforces.com/contest/1352/problem/G

void solve()
{
    int n;
    cin >> n;

    switch (n) {
        case 1: {
            cout << "1";
            return;
        }
        case 2:
        case 3: {
            cout << "NO SOLUTION";
            return;
        }
        case 4: {
            cout << "3 1 4 2";
            return;
        }
        default: {
            int left = n - (n % 2 == 1);
            int right = n - (n % 2 == 0);

            for (int i = left; i > 4; i -= 2)
                cout << i << " ";

            cout << "3 1 4 2 ";

            for (int i = 5; i <= right; i += 2)
                cout << i << " ";
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    solve();

    return 0;
}
