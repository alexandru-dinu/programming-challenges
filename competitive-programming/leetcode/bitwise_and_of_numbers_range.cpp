// https://leetcode.com/problems/bitwise-and-of-numbers-range

class Solution
{
  public:
    function<int(int)> msb = [](int x) {
        return x ? 32 - __builtin_clz(x) : 0;
    };

    int f(int x, int y)
    {
        int mx = msb(x);
        int my = msb(y);

        if (mx != my)
            return 0;

        // remove msb for x, y
        // -1 because msb(.) return 1-indexed
        int m = mx - 1;
        x &= ~(1 << m);
        y &= ~(1 << m);

        return (1 << m) + f(x, y);
    }

    int rangeBitwiseAnd(int x, int y)
    {
        return (x == y) ? x : f(x, y);
    }
};