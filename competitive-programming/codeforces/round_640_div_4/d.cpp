#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long

void solve(int tc)
{
    int n;
    cin >> n;

    vector<int> xs(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> xs[i];

    int rounds = 0;
    int a_lim = 0;
    int b_lim = 0;
    int a_i = 0;
    int b_i = n - 1;
    int a_ate = 0;
    int b_ate = 0;

    while (a_i <= b_i) {
        // alice
        if (rounds % 2 == 0) {
            int eat = 0;
            while (a_i <= b_i && eat <= a_lim) {
                eat += xs[a_i++];
            }
            b_lim = eat;
            a_ate += eat;
        }

        // bob
        else {
            int eat = 0;
            while (a_i <= b_i && eat <= b_lim) {
                eat += xs[b_i--];
            }
            a_lim = eat;
            b_ate += eat;
        }

        ++rounds;
    }

    cout << rounds << " " << a_ate << " " << b_ate << "\n";
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
