// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution
{
  public:
    int bs(const vector<int> &nums, int target)
    {
        int l = 0, r = nums.size() - 1;
        int mid;

        /*
         * default value = array size
         * intuitively, if x >= target is not found in nums
         * then it is "after" the end of the array
         */
        int pos = nums.size();

        while (l <= r) {
            mid = l + (r - l) / 2;
            if (nums[mid] >= target) {
                pos = mid;
                r = mid - 1;
            } else
                l = mid + 1;
        }

        return pos;
    }

    vector<int> searchRange(vector<int> &nums, int target)
    {
        // idea: use b.s. to find index of
        // (>= target, >= target+1)

        int lo = bs(nums, target);
        int hi = bs(nums, target + 1) - 1; // because want <= target

        /*
         * if some x >= target is not found,
         * it is clear that no x >= target + 1 will be found as well
         * so, in this case, lo = hi - 1, returning {-1, -1}
         */

        if (lo > hi)
            lo = hi = -1;

        return { lo, hi };
    }
};