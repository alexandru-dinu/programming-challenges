// https://leetcode.com/problems/all-paths-from-source-to-target

class Solution
{
  public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> paths;
        vector<int> path;

        if (graph.size() == 0)
            return {};

        aux(graph, paths, path, 0, graph.size() - 1);

        return paths;
    }

    void aux(vector<vector<int>> &graph,
             vector<vector<int>> &paths,
             vector<int> path,
             int s,
             int d)
    {
        path.push_back(s);

        if (s == d) {
            paths.push_back(path);
            return;
        }

        for (auto &n : graph[s])
            aux(graph, paths, path, n, d);
    }
};