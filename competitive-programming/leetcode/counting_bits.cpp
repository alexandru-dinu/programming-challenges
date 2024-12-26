// https://leetcode.com/problems/counting-bits

class Solution
{
  public:
    vector<int> countBits(int num)
    {
        vector<int> ans(num + 1, 0);

        // sol 1: most convenient
        // for (int i = 0; i <= num; i++)
        //     ans[i] = __builtin_popcount(i);

        // sol 2: w/o builtin, ~dp
        int lpow = 0;

        for (int i = 1; i <= num; i++) {
            // is power of 2: only 1 bit set
            if ((i & (i - 1)) == 0) {
                ans[i] = 1;
                lpow = i;
            }
            // otherwise, this number has an extra bit set (from the largest
            // power of 2) from what we've already computed
            else {
                ans[i] = ans[i - lpow] + 1;
            }
        }

        return ans;
    }
};