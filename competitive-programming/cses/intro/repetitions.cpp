#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long

void solve()
{
    string s;
    cin >> s;

    int res = 1;
    int j = 0;
    int i = 1;
    char c = s[j];

    while (i < s.length()) {
        while (i < s.length() && s[i] == c) {
            ++i;
        }
        res = max(res, i - j);
        c = s[i];
        j = i;
        ++i;
    }

    cout << res << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    solve();

    return 0;
}
