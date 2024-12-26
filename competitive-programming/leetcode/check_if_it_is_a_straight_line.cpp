// https://leetcode.com/problems/check-if-it-is-a-straight-line

class Solution
{
  public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        const int l = coordinates.size();

        auto &p1 = coordinates[0];
        auto &p2 = coordinates[l - 1];

        function<bool(int, int)> on_line;

        if (p2[0] == p1[0]) {
            int x1 = p1[0];
            on_line = [x1](int x, int y) { return x == x1; };
        } else {
            double m = (p2[1] - p1[1]) / (p2[0] - p1[0]);
            double n = p1[1] - m * p1[0];
            on_line = [m, n](int x, int y) { return y == m * x + n; };
        }

        for (int i = 1; i < l - 1; i++) {
            auto &p = coordinates[i];

            if (not on_line(p[0], p[1]))
                return false;
        }

        return true;
    }
};