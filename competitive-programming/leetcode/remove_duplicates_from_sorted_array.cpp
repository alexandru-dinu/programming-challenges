// https://leetcode.com/problems/remove-duplicates-from-sorted-array

class Solution
{
  public:
    int removeDuplicates(vector<int> &nums)
    {

        int k = 0, n = nums.size();

        if (nums.size() < 2)
            return n;

        for (int i = 1; i < nums.size(); i++)
            if (nums[i] != nums[i - 1])
                nums[k++] = nums[i - 1];

        nums[k++] = nums[n - 1];

        return k;
    }
};