// https://leetcode.com/problems/two-sum

class Solution
{
  public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        std::map<int, int> m;
        std::vector<int> pair;

        for (size_t i = 0; i < nums.size(); ++i) {
            int to_find = target - nums[i];

            if (m.find(to_find) != m.end()) {
                pair.push_back(m[to_find]);
                pair.push_back(i);
            }

            m[nums[i]] = i;
        }

        return pair;
    }
};