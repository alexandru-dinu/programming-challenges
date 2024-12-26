// https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number

class Solution
{
  public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        unordered_map<int, int> m;

        for (int x : nums)
            ++m[x];

        for (int i = 1; i <= 100; i++)
            m[i] += m[i - 1];

        for (int i = 0; i < n; i++)
            ans[i] = (nums[i] == 0) ? 0 : m[nums[i] - 1];

        return ans;
    }
};