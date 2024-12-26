#include <bits/stdc++.h>
#include <iostream>

using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    string s;
    cin >> s;

    s[0] -= (s[0] >= 97) << 5;
    cout << s;

    return 0;
}
