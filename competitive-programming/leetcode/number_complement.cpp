// https://leetcode.com/problems/number-complement

class Solution
{
  public:
    int findComplement(int num)
    {
        uint32_t m = ~0;

        // make mask 111111...111|00..00
        //            leading 0s | num
        while (num & m)
            m <<= 1;

        // only keep relevant bits from ~num
        // i.e. discard leading 1s
        return ~m & ~num;
    }
};