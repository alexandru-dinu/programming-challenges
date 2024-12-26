#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long

void solve()
{
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    sort(s.begin(), s.end());

    // if smallest k letters are not equal,
    // answer is the k-th smallest letter
    if (s[0] != s[k - 1]) {
        cout << s[k - 1] << "\n";
        return;
    }

    if (s[k] != s[n - 1])
        cout << s.substr(k - 1);
    else
        cout << s[k - 1] << string((n - 1) / k, s[n - 1]);

    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
        solve();

    return 0;
}
