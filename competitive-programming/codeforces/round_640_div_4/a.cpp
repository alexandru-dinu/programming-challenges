#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long
#define sol_t void

sol_t solve(int tc)
{
    int n;
    cin >> n;

    vector<int> xs;
    int k = 1;
    while (n) {
        int r = (n % 10) * k;
        if (r != 0)
            xs.push_back(r);
        n /= 10;
        k *= 10;
    }

    int m = xs.size();
    cout << m << "\n";
    for (int i = m - 1; i >= 0; --i) {
        cout << xs[i] << " ";
    }
    cout << "\n";

    return;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int tc;

    // tc = 1;
    cin >> tc;

    while (tc--) {
        solve(tc);
    }

    return 0;
}
