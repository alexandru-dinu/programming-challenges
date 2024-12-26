// https://leetcode.com/problems/sqrtx

class Solution
{
  public:
    int mySqrt(int s)
    {
        if (s == 0)
            return 0;

        double eps = 1e-1;
        double x0 = s / 3.0, x1;

        while (true) {
            x1 = (x0 * x0 + s) / (2 * x0);
            if (std::abs(x1 - x0) <= eps)
                break;
            x0 = x1;
        }

        return (int)std::floor(x1);
    }
};