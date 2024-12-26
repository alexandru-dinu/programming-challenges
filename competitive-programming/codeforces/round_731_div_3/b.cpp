#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long
#define output_t void

output_t solve(int tc)
{
    string s;
    cin >> s;

    size_t n = s.length();
    size_t k = -1, l = 0, h = 0;

    // find 'a'
    k = s.find('a');
    if (k == string::npos) {
        cout << "NO\n";
        return;
    }

    l = k - 1;
    h = k + 1;

    for (size_t i = 1; i < n; ++i) {
        char c = 'a' + i;
        // must find c at l or h

        if (0 <= l && s[l] == c) {
            --l;
        } else if (h < n && s[h] == c) {
            ++h;
        } else {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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
