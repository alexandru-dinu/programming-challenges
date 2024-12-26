// https://leetcode.com/problems/contiguous-array

class Solution
{
  public:
    int findMaxLength(vector<int> &nums)
    {
        unordered_map<int, int> m;
        int n = nums.size();
        int maxlen = 0;
        int cnt = 0;

        m[0] = 0;

        for (int i = 0; i < n; i++) {
            cnt += (nums[i] == 0) ? -1 : 1;

            // encountered this count before
            // => have an equal number of 0's and 1's
            if (m.find(cnt) != m.end())
                maxlen = max(maxlen, i + 1 - m[cnt]);
            else
                m[cnt] = i + 1;
        }

        return maxlen;
    }
};