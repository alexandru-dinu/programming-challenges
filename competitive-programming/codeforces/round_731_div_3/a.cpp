#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long
#define output_t void

using point_t = pair<int, int>;

bool ordered(int a, int b, int c)
{
    return (a < b && b < c) || (a > b && b > c);
}

bool same_row(point_t a, point_t b, point_t c)
{
    return (a.second == b.second) and (b.second == c.second);
}

bool same_col(point_t a, point_t b, point_t c)
{
    return (a.first == b.first) and (b.first == c.first);
}

output_t solve(int tc)
{
    point_t a, b, f;

    cin >> a.first >> a.second;
    cin >> b.first >> b.second;
    cin >> f.first >> f.second;

    size_t ans = abs(a.first - b.first) + abs(a.second - b.second);

    bool row_test = same_row(a, b, f) && ordered(a.first, f.first, b.first);
    bool col_test = same_col(a, b, f) && ordered(a.second, f.second, b.second);

    ans = ans + 2 * (row_test || col_test);

    cout << ans << "\n";
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
