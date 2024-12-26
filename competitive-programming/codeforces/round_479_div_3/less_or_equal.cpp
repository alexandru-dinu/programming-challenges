#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long
#define sol_t int

#define LIM 1000000000

sol_t solve(int tc)
{
    int n, k;
    cin >> n >> k;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(begin(v), end(v));

    if (k == 0)
        return (v[0] == 1) ? -1 : v[0] - 1;

    int ans = v[k - 1], cnt = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] > ans)
            break;
        ++cnt;
    }

    if (cnt != k or ans < 1 or ans > LIM)
        return -1;

    return ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int tc;

    tc = 1;
    // cin >> tc;

    while (tc--) {
        cout << solve(tc) << "\n";
    }

    return 0;
}
