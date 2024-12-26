// https://leetcode.com/problems/online-stock-span

class StockSpanner
{
  private:
    // {price, count_<=_than_me}
    stack<pair<int, int>> s;

  public:
    StockSpanner()
      : s()
    {}

    int next(int price)
    {
        int r = 1;

        while (!s.empty() and s.top().first <= price) {
            r += s.top().second;
            s.pop();
        }

        s.push({ price, r });

        return r;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */