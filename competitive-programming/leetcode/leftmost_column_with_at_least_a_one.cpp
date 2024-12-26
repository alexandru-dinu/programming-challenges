// https://leetcode.com/problems/leftmost-column-with-at-least-a-one

/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution
{
  public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix)
    {
        vector<int> dims = binaryMatrix.dimensions();
        int n = dims[0], m = dims[1];

        int ans = m;

        for (int i = 0; i < n; ++i) {
            // BS to find index of first 1 on row i

            if (ans == 0) // already found the best
                break;

            // it's sufficient to only search [0, ans - 1],
            // since anything in [ans, m] will not improve the result
            int pos = -1;
            int lo = 0;
            int hi = ans - 1;

            if (binaryMatrix.get(i, hi) == 0)
                continue;

            while (lo <= hi) {
                int mid = lo + (hi - lo) / 2;

                if (1 == binaryMatrix.get(i, mid)) {
                    ans = min(ans, mid);
                    hi = mid - 1;
                } else {
                    lo = mid + 1;
                }
            }
        }

        return (ans == m) ? -1 : ans;
    }
};