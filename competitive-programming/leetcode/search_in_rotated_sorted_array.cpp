// https://leetcode.com/problems/search-in-rotated-sorted-array

class Solution
{
  public:
    int search(vector<int> &nums, int target)
    {
        const int n = nums.size();

        // 1. find index of smallest element using BS
        int lo = 0, hi = n - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (nums[mid] >= nums[hi])
                lo = mid + 1;
            else
                hi = mid;
        }

        int rot = lo; // == hi;

        // 2. find target using BS, accounting for the rotation
        lo = 0;
        hi = n - 1;

        auto rotate = [n, rot](int i) { return (i + rot) % n; };

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int rmid = rotate(mid);

            if (nums[rmid] == target)
                return rmid;

            if (target < nums[rmid])
                hi = mid - 1;
            else
                lo = mid + 1;
        }

        return -1;
    }
};