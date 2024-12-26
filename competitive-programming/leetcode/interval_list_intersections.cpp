// https://leetcode.com/problems/interval-list-intersections

class Solution
{
  public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &A,
                                             vector<vector<int>> &B)
    {
        const int nA = A.size();
        const int nB = B.size();

        vector<vector<int>> ans;

        int i = 0, j = 0;

        while (i < nA and j < nB) {
            int start = max(A[i][0], B[j][0]);
            int end = min(A[i][1], B[j][1]);

            if (start <= end)
                ans.push_back({ start, end });

            if (A[i][1] < B[j][1])
                i++;
            else
                j++;
        }

        return ans;
    }
};