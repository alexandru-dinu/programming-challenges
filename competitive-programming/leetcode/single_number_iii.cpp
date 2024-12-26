// https://leetcode.com/problems/single-number-iii

class Solution
{
  public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int xr = 0;
        for (int x : nums)
            xr ^= x;

        // xr = e1 ^ e2
        int e1 = 0, e2 = 0;

        // e1, e2 differ in at least 1 bit
        // get rightmost set bit
        int diff_bit = xr & -xr;

        // group according to diff_bit
        for (int x : nums) {
            if (!(x & diff_bit))
                e1 ^= x;
            else
                e2 ^= x;
        }

        return { e1, e2 };
    }
};