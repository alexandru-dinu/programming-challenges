// https://leetcode.com/problems/longest-string-chain

class Solution
{

    vector<vector<int>> graph;
    vector<int> cache;

    int longest(int x)
    {
        if (cache[x] > 0)
            return cache[x];

        cache[x] = 1;
        for (int neigh : graph[x])
            cache[x] = max(cache[x], longest(neigh) + 1);

        return cache[x];
    }

  public:
    int longestStrChain(vector<string> &words)
    {
        int n = words.size();
        unordered_map<string, int> pos;
        graph.clear();
        graph.resize(n);
        cache.clear();
        cache.resize(n);

        for (int i = 0; i < n; i++)
            pos[words[i]] = i;

        for (int i = 0; i < n; i++) {
            string s = words[i];

            // check if by eliminating j'th char, we get a string in the input
            // if so, add edge (shorter -> longer)
            for (int j = 0; j < s.size(); j++) {
                string ss = s.substr(0, j) + s.substr(j + 1);

                if (pos.find(ss) != pos.end())
                    graph[pos[ss]].push_back(i);
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++)
            ans = max(ans, longest(i));

        return ans;
    }
};