// https://leetcode.com/problems/jump-game

class Solution
{
  public:
    bool bottom_up_dp(const vector<int> &nums)
    {
        const int n = nums.size();

        vector<unsigned char> is_good(n, false);
        is_good[n - 1] = true;

        for (int i = n - 2; i >= 0; --i) {
            int max_jump = min(i + nums[i], n - 1);

            for (int next = i + 1; next <= max_jump; ++next) {
                if (is_good[next]) {
                    is_good[i] = true;
                    break;
                }
            }
        }

        return is_good[0];
    }

    bool greedy(const vector<int> &nums)
    {
        const int n = nums.size();
        int last_good = n - 1;

        for (int i = n - 1; i >= 0; --i)
            // last_good can be reached from pos i => pos i is good
            if (i + nums[i] >= last_good)
                last_good = i;

        return last_good == 0;
    }

    bool canJump(vector<int> &nums)
    {
        // return bottom_up_dp(nums);
        return greedy(nums);
    }
};