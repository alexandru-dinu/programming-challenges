// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array

class Solution
{
  public:
    vector<int> with_extra_memory(const vector<int> &nums)
    {
        unordered_set<int> m;
        int n = nums.size();

        for (int i : nums)
            m.insert(i);

        vector<int> ans;

        for (int i = 1; i <= n; i++) {
            if (m.find(i) == m.end())
                ans.push_back(i);
        }

        return ans;
    }

    vector<int> without_extra_memory(vector<int> &nums)
    {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int j = abs(nums[i]) - 1;

            // only mark non-visited (i.e. positive) numbers
            if (nums[j] > 0)
                nums[j] *= -1;
        }

        vector<int> ans;

        // look for unmarked (i.e. positive) numbers
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0)
                ans.push_back(i + 1);
        }

        return ans;
    }

    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        // O(N) time + space
        // return with_extra_memory(nums);

        // O(N) time, O(1) memory
        return without_extra_memory(nums);
    }
};