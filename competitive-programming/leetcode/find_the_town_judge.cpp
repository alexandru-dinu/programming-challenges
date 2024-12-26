// https://leetcode.com/problems/find-the-town-judge

class Solution
{
  public:
    int findJudge(int N, vector<vector<int>> &trust)
    {
        if (N == 1)
            return 1;

        vector<pair<int, int>> v(N + 1, { 0, 0 });

        for (auto &p : trust) {
            v[p[0]].first++;  // how many times voted
            v[p[1]].second++; // how many votes received
        }

        for (int i = 1; i <= N; i++) {
            if (v[i].first == 0 and v[i].second == N - 1)
                return i;
        }

        return -1;
    }
};