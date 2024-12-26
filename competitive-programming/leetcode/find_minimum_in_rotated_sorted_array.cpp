// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array

class Solution
{
  public:
    int aux(vector<int> &nums, int lo, int hi)
    {
        int mid = lo + (hi - lo) / 2;

        if (lo == hi)
            return nums[lo];

        if (nums[lo] > nums[hi])
            return std::min(aux(nums, lo, mid), aux(nums, mid + 1, hi));
        else
            return nums[lo];
    }
    int findMin(vector<int> &nums)
    {
        return aux(nums, 0, nums.size() - 1);
    }
};