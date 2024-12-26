// https://leetcode.com/problems/search-a-2d-matrix-ii

class Solution
{
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty() or matrix[0].empty())
            return false;

        const int m = matrix.size();
        const int n = matrix[0].size();

        if (target < matrix[0][0] or target > matrix[m - 1][n - 1])
            return false;

        for (int col = 0; col < n; ++col) {
            // apply BS on column [:, col]

            if (target < matrix[0][col])
                return false;

            if (target > matrix[m - 1][col])
                continue;

            int lo = 0, hi = m - 1;

            while (lo <= hi) {
                int row = lo + (hi - lo) / 2;
                int val = matrix[row][col];

                if (val == target)
                    return true;

                if (target < val)
                    hi = row - 1;
                else
                    lo = row + 1;
            }

            // target not found on col, move forward
        }

        return false;
    }
};