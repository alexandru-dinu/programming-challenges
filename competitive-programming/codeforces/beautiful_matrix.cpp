#include <iostream>

using namespace std;

int main()
{
    int ans = -1;

    for (int x, i = 0; i < 25; i++) {
        cin >> x;

        if (x == 1) {
            ans = abs(i / 5 - 2) + abs(i % 5 - 2);
            break;
        }
    }

    cout << ans << "\n";

    return 0;
}