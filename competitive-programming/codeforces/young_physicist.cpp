#include <iostream>

using namespace std;

int main()
{
    int n, x, y, z, sx(0), sy(0), sz(0);
    cin >> n;

    while (n--) {
        cin >> x >> y >> z;
        sx += x;
        sy += y;
        sz += z;
    }

    cout << ((sx == 0 && sy == 0 && sz == 0) ? "YES" : "NO") << endl;

    return 0;
}