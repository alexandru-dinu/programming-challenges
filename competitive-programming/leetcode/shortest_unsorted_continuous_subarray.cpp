// https://leetcode.com/problems/shortest-unsorted-continuous-subarray

class Solution
{
  public:
    int findUnsortedSubarray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> vs(n);
        partial_sort_copy(begin(nums), end(nums), begin(vs), end(vs));

        int im = 0, iM = n - 1;

        while (im < n && nums[im] == vs[im])
            ++im;

        while (iM >= 0 && nums[iM] == vs[iM])
            --iM;

        if (im > iM)
            return 0;

        return iM - im + 1;
    }
};