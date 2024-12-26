// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero

#include <bitset>

class Solution
{
  public:
    int numberOfSteps(int num)
    {
        if (num == 0)
            return 0;

        // how many times to divide by 2
        int x1 = static_cast<int>(floor(log2(num)));

        // how many times to subtract 1
        int x2 = bitset<32>(num).count();

        return x1 + x2;
    }
};