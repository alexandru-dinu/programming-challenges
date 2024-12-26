// https://leetcode.com/problems/power-of-four

class Solution
{
  public:
    bool isPowerOfFour(int num)
    {

        int x = abs(num);

        bool b1 = (x & (x - 1)) == 0;
        bool b2 = (static_cast<uint32_t>(x) & 0x55555555) != 0;

        return (num > 0) && b1 && b2;
    }
};