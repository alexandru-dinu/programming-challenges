// https://leetcode.com/problems/decompress-run-length-encoded-list

class Solution
{
  public:
    vector<int> decompressRLElist(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans;

        for (int i = 0; i < n / 2; i++) {
            int f = nums[2 * i], v = nums[2 * i + 1];
            vector<int> t(f, v);
            move(t.begin(), t.end(), back_inserter(ans));
        }

        return ans;
    }
};