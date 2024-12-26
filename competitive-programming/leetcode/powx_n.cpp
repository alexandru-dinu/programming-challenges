// https://leetcode.com/problems/powx-n

class Solution
{
  public:
    double _pow(double x, int n)
    {
        if (n == 0)
            return 1.0;
        if (n % 2 == 0) {
            double r = _pow(x, n / 2);
            return r * r;
        } else
            return x * _pow(x, n - 1);
    }

    double myPow(double x, int n)
    {
        int sign = (n < 0) ? -1 : 1;

        if (x == 1.0)
            return 1.0;
        if (x == -1.0 && sign == -1)
            return 1.0;

        if (n == 0.0)
            return 1.0;
        if (n == 1.0)
            return x;

        if (n == std::numeric_limits<int>::min())
            return 0.0;

        double ans = _pow(x, sign * n);

        if (sign == -1)
            return 1.0 / ans;
        else
            return ans;
    }
};