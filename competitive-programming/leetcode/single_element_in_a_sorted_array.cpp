// https://leetcode.com/problems/single-element-in-a-sorted-array

class Solution
{
  public:
    int singleNonDuplicate(vector<int> &nums)
    {
        /* key idea, if no duplicates were involved:
         * even idx has pair on idx+1
         * odd  idx has pair on idx-1
         */
        int n = nums.size();
        int l = 0, r = n - 1;

        while (l != r) {
            int m = l + (r - l) / 2;

            if (m % 2 == 0) {
                if (nums[m] != nums[m + 1])
                    r = m;
                else
                    l = m + 2;
            } else {
                if (nums[m] != nums[m - 1])
                    r = m - 1;
                else
                    l = m + 1;
            }
        }

        return nums[l];
    }
};