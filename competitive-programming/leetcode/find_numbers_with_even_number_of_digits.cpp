// https://leetcode.com/problems/find-numbers-with-even-number-of-digits

class Solution
{
  public:
    int findNumbers(vector<int> &nums)
    {
        int ans = 0;

        for (int x : nums) {
            x = max(x, 2); // log(1) == 0
            ans += (static_cast<int>(ceil(log10(x))) % 2 == 0);
        }

        return ans;
    }
};