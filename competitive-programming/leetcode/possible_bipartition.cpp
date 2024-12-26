// https://leetcode.com/problems/possible-bipartition

class Solution
{
    using graph_t = unordered_map<int, vector<int>>;

  public:
    bool dfs(graph_t &g,
             unordered_map<int, bool> &colored,
             int node,
             bool color)
    {
        // if visited, make sure it's the expected color
        if (colored.find(node) != colored.end())
            return colored[node] == color;

        colored[node] = color;

        for (int u : g[node]) {
            bool r = dfs(g, colored, u, !color);
            if (!r)
                return false;
        }
        return true;
    }

    bool possibleBipartition(int N, vector<vector<int>> &dislikes)
    {
        graph_t g;

        for (auto &p : dislikes) {
            g[p[0]].push_back(p[1]);
            g[p[1]].push_back(p[0]);
        }

        unordered_map<int, bool> colored;

        for (int i = 1; i <= N; ++i) {
            if (colored.find(i) != colored.end())
                continue;

            bool r = dfs(g, colored, i, 0);
            if (!r)
                return false;
        }

        return true;
    }
};