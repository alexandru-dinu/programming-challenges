// https://leetcode.com/problems/coin-change

class Solution
{
  public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> F(amount + 1, amount + 1);
        F[0] = 0;

        for (int i = 1; i <= amount; i++) {
            int min = amount + 1;

            for (int j = 0; j < coins.size(); j++) {
                if (i >= coins[j]) {
                    min = std::min(min, F[i - coins[j]]);
                }
            }

            F[i] = min + 1;
        }

        return F[amount] > amount ? -1 : F[amount];
    }
};