#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long

/*
 * 0 = .
 * 1 = -.
 * 2 = --
 */

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    string s;
    cin >> s;

    vector<int> v;

    int i = 0;

    while (i < s.length()) {
        if (s[i] == '-') {
            v.push_back((s[i + 1] == '.') ? 1 : 2);
            i += 2;
        } else {
            v.push_back(0);
            i++;
        }
    }

    for (int x : v) {
        cout << x;
    }

    return 0;
}
