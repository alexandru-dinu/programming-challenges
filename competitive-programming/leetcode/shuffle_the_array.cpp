// https://leetcode.com/problems/shuffle-the-array

class Solution
{
  public:
    vector<int> shuffle(vector<int> &nums, int n)
    {
        vector<int> s(2 * n, 0);

        for (int i = 0; i < 2 * n; i++) {
            // s[2 * (i - n * (i >= n)) + (i >= n)] = nums[i];
            s[2 * i + (i >= n) * (1 - 2 * n)] = nums[i];
        }

        return s;
    }
};