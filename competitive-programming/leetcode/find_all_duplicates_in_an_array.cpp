// https://leetcode.com/problems/find-all-duplicates-in-an-array

class Solution
{
  public:
    vector<int> findDuplicates(vector<int> &nums)
    {
        std::vector<int> res;

        for (int i = 0; i < nums.size(); i++) {
            int idx = abs(nums[i]) - 1;

            nums[idx] *= -1;

            if (nums[idx] > 0)
                res.push_back(abs(nums[i]));
        }

        return res;
    }
};