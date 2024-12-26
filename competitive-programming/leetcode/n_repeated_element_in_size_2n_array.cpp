// https://leetcode.com/problems/n-repeated-element-in-size-2n-array

#include <set>

class Solution
{
  public:
    int repeatedNTimes(vector<int> &A)
    {
        for (int i = 0; i < A.size() - 1; i++) {
            if (A[i] == A[i + 1])
                return A[i];
        }

        if (A[0] == A[2] || A[0] == A[3])
            return A[0];

        return A[1];
    }
};