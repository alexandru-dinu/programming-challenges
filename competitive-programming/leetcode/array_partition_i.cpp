// https://leetcode.com/problems/array-partition-i

class Solution
{
  public:
    int arrayPairSum(vector<int> &nums)
    {

        vector<int> v = nums;

        std::sort(v.begin(), v.end());

        int sum = 0;

        for (int i = 0; i < v.size(); i += 2)
            sum += v[i];

        return sum;
    }
};