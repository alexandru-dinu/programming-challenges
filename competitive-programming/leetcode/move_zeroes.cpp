// https://leetcode.com/problems/move-zeroes

class Solution
{
  public:
    void moveZeroes(vector<int> &nums)
    {
        // move every non-zero to the beginning
        int n = nums.size();
        int p = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                nums[p++] = nums[i];
            }
        }

        for (int i = p; i < n; i++)
            nums[i] = 0;
    }
};