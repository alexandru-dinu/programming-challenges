// https://leetcode.com/problems/two-city-scheduling

class Solution
{
  public:
    int twoCitySchedCost(vector<vector<int>> &costs)
    {
        const int n = costs.size() / 2;

        sort(costs.begin(), costs.end(), [](const auto &v1, const auto &v2) {
            return (v1[0] - v1[1]) < (v2[0] - v2[1]);
        });

        int cost = 0;
        for (int i = 0; i < n; i++) {
            cost += costs[i][0] + costs[i + n][1];
        }

        return cost;
    }
};