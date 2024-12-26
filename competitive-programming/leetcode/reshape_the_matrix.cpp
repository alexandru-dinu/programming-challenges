// https://leetcode.com/problems/reshape-the-matrix

class Solution
{
  public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c)
    {
        vector<vector<int>> out(r);

        for (int i = 0; i < r; i++)
            out[i] = std::vector<int>(c);

        if (nums.size() < 1 || r * c != nums.size() * nums[0].size())
            return nums;

        int ri = 0, ci = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums[0].size(); j++) {
                out[ri][ci] = nums[i][j];
                ci++;

                if (ci == c) {
                    ci = 0;
                    ri++;
                }
            }
        }

        return out;
    }
};