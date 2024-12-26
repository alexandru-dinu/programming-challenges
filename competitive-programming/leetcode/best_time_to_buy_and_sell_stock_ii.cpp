// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii

class Solution
{
  public:
    int maxProfit(vector<int> &prices)
    {
        int stock = INT_MIN, no_stock = 0;

        for (int p : prices) {
            stock = max(stock, no_stock - p);    // buy
            no_stock = max(no_stock, stock + p); // sell
        }

        return no_stock;
    }
};