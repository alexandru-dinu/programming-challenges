#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

#define ll long long

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);

    string s;
    cin >> s;

    int l = 0, u = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] < 97)
            u++;
        else
            l++;
    }

    if (l >= u)
        transform(s.begin(), s.end(), s.begin(), ::tolower);
    else
        transform(s.begin(), s.end(), s.begin(), ::toupper);

    cout << s;

    return 0;
}
