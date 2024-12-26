// https://leetcode.com/problems/search-a-2d-matrix

class Solution
{
  public:
    bool bs(const vector<int> &xs, int target)
    {
        const int n = xs.size();
        int lo = 0, hi = n - 1;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;

            if (xs[mid] == target)
                return true;

            if (target < xs[mid])
                hi = mid - 1;
            else
                lo = mid + 1;
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty() or matrix[0].empty())
            return false;

        const int m = matrix.size();
        const int n = matrix[0].size();

        // 1. find row index
        int lo = 0, hi = m - 1;
        int row;

        while (lo <= hi) {
            row = lo + (hi - lo) / 2;
            int val_lo = matrix[row][0];
            int val_hi = matrix[row][n - 1];

            if (val_lo == target or val_hi == target)
                return true;

            // found row -> apply bs
            if (val_lo < target and target < val_hi)
                return bs(matrix[row], target);

            if (target < val_lo)
                hi = row - 1;
            else
                lo = row + 1;
        }

        return false;
    }
};