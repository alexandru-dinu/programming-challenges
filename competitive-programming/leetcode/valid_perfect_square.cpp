// https://leetcode.com/problems/valid-perfect-square

class Solution
{
  public:
    bool isPerfectSquare(int num)
    {
        uint64_t l = 1, r = num;

        while (l <= r) {
            uint64_t mid = l + (r - l) / 2;

            if (mid == 1.0 * num / mid)
                return true;

            if (mid > num / mid)
                r = mid - 1;
            else
                l = mid + 1;
        }

        return false;
    }
};