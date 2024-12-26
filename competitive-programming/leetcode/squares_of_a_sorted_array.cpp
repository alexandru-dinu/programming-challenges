// https://leetcode.com/problems/squares-of-a-sorted-array

class Solution
{
  public:
    vector<int> sortedSquares(vector<int> &A)
    {
        const int n = A.size();

        transform(begin(A), end(A), begin(A), [](int x) { return x * x; });

        if (n == 1)
            return A;

        // [0, m): decreasing (left)
        // [m, n): increasing (right)
        int m = n;

        for (int i = 1; i < n; ++i) {
            if (A[i - 1] < A[i]) {
                m = i - 1;
                break;
            }
        }

        // A is already correctly sorted
        if (m == 0)
            return A;

        // merge left & right parts
        int l = m - 1;
        int r = m;
        int k = 0;
        vector<int> ans(n);

        while (l >= 0 and r < n) {
            if (A[l] < A[r]) {
                ans[k++] = A[l];
                l--;
            } else {
                ans[k++] = A[r];
                r++;
            }
        }

        while (l >= 0)
            ans[k++] = A[l--];

        while (r < n)
            ans[k++] = A[r++];

        return ans;
    }
};