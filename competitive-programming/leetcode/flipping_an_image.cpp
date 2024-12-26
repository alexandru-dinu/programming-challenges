// https://leetcode.com/problems/flipping-an-image

class Solution
{
  public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A)
    {
        int r = A.size();
        int c = A[0].size();

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < (c + 1) / 2; j++) {
                A[i][j] ^= 1;
                A[i][c - 1 - j] ^= (j != c - 1 - j);

                std::swap(A[i][j], A[i][c - 1 - j]);
            }
        }

        return A;
    }
};