// https://leetcode.com/problems/candy

class Solution
{
  public:
    int candy(vector<int> &ratings)
    {
        int n = ratings.size();
        int res = 0;

        std::vector<int> lr(n, 1);
        std::vector<int> rl(n, 1);

        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1])
                lr[i] = lr[i - 1] + 1;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (ratings[i - 1] > ratings[i])
                rl[i - 1] = rl[i] + 1;
        }
        for (int i = 0; i < n; i++) {
            res += std::max(lr[i], rl[i]);
        }

        return res;
    }
};