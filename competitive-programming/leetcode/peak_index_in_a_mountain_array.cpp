// https://leetcode.com/problems/peak-index-in-a-mountain-array

class Solution
{
  public:
    int peakIndexInMountainArray(vector<int> &A)
    {
        int idx = 0, max = -1;

        for (int i = 0; i < A.size(); i++) {
            if (A[i] > max) {
                max = A[i];
                idx = i;
            }
        }

        return idx;
    }
};