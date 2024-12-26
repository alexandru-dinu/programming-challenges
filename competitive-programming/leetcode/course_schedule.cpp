// https://leetcode.com/problems/course-schedule

class Solution
{
  public:
    bool canFinish(int n, vector<vector<int>> &prereq)
    {
        // Topological sorting
        vector<vector<int>> g(n);
        vector<int> deg(n, 0), bfs;

        for (auto &edge : prereq) {
            g[edge[1]].push_back(edge[0]);
            deg[edge[0]]++;
        }

        for (int i = 0; i < n; ++i) {
            // courses w/o prereq
            if (deg[i] == 0)
                bfs.push_back(i);
        }

        for (int i = 0; i < bfs.size(); ++i) {
            for (int j : g[bfs[i]]) {
                // "remove" edge i -> j, add j if no more in-edges
                if (--deg[j] == 0)
                    bfs.push_back(j);
            }
        }

        return bfs.size() == n;
    }
};