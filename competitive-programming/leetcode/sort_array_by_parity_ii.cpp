// https://leetcode.com/problems/sort-array-by-parity-ii

class Solution
{
  public:
    vector<int> sortArrayByParityII(vector<int> &A)
    {
        int i = 0, j = 1;

        for (i = 0; i < A.size(); i += 2) {
            if (A[i] % 2 == 0)
                continue;

            while (A[j] % 2 == 1)
                j += 2;

            std::swap(A[i], A[j]);
        }

        return A;
    }
};