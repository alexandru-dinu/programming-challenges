// https://leetcode.com/problems/single-number

class Solution
{
  public:
    int singleNumber(vector<int> &nums)
    {
        return accumulate(
          begin(nums), end(nums), 0, [](int acc, int x) { return acc ^ x; });
    }
};