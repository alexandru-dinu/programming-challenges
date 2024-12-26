#include <cmath>
#include <iostream>
#include <map>
#include <stdint.h>

using namespace std;

int main(int argc, char const *argv[])
{

    int lim = 1000000;

    map<uint64_t, uint64_t> cache;

    uint64_t shared_max = 0;
    uint64_t shared_X = 0;

    for (int i = 3; i <= lim; i++) {
        uint64_t st = 1;
        uint64_t x = i;

        while (x != 1) {
            if (cache.find(x) != cache.end()) {
                st += cache[x];
                break;
            }

            if (!(x & 1))
                x = x / 2;
            else
                x = 3 * x + 1;

            st++;
        }

        if (st > shared_max) {
            shared_max = st;
            shared_X = i;
        }

        cache[i] = st;
    }

    cout << shared_X << " -> " << shared_max << endl;

    return 0;
}
