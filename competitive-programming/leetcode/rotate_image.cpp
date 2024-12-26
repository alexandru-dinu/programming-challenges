// https://leetcode.com/problems/rotate-image

class Solution
{
  public:
    void rotate(vector<vector<int>> &matrix)
    {
        std::size_t n = matrix.size();

        for (int i = 0; i < n / 2; i++) {
            std::swap(matrix[i], matrix[n - 1 - i]);
        }

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
};