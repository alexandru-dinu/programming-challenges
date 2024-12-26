// https://leetcode.com/problems/max-consecutive-ones

class Solution
{
  public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int maxlen = -1;
        int cnt = 0;

        for (int x : nums) {
            if (x == 1) {
                ++cnt;
            } else {
                maxlen = max(maxlen, cnt);
                cnt = 0;
            }
        }

        return max(maxlen, cnt);
    }
};