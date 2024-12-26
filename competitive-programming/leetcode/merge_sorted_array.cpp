// https://leetcode.com/problems/merge-sorted-array

class Solution
{
  public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i1 = m - 1, i2 = n - 1, it = m + n - 1;

        while (i1 >= 0 && i2 >= 0) {
            nums1[it--] = (nums1[i1] >= nums2[i2]) ? nums1[i1--] : nums2[i2--];
        }

        while (i2 >= 0) {
            nums1[it--] = nums2[i2--];
        }
    }
};