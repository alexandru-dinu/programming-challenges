#include <bits/stdc++.h>
#include <iostream>

using namespace std;

const int MAXN = 1e5;

using pair_t = pair<int, int>;
using graph_t = vector<list<pair_t>>;

list<int> dijkstra(int s, int t, const graph_t &g)
{
    int n = g.size();

    bitset<MAXN> visited;
    priority_queue<pair_t, vector<pair_t>, greater<pair_t>> q;

    vector<int> dist(n, INT_MAX);
    vector<int> prev(n, -1);

    q.push(make_pair(0, s));
    dist[s] = 0;
    prev[s] = -1;

    bool has_path = false;

    while (!q.empty()) {
        int u = q.top().second;
        q.pop();

        if (u == t) {
            has_path = true;
            break;
        }

        visited[u] = true;

        for (const pair_t &p : g[u]) {
            int v = p.first;

            if (visited[v])
                continue;

            int w = p.second;
            int alt = dist[u] + w;

            if (alt < dist[v]) {
                dist[v] = alt;
                prev[v] = u;
                q.push(make_pair(alt, v));
            }
        }
    }

    // reconstruct path, if any
    int u = t;

    if (!has_path or (prev[u] == -1 and u != s))
        return { -1 };

    list<int> path;

    while (u != -1) {
        path.push_front(u + 1);
        u = prev[u];
    }

    return path;
}

int main()
{
    int n, m;
    cin >> n >> m;

    int s = 0;     // source
    int t = n - 1; // destination

    graph_t g(n);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u - 1].push_back(make_pair(v - 1, w));
        g[v - 1].push_back(make_pair(u - 1, w));
    }

    list<int> shortest_path = dijkstra(s, t, g);

    for (int u : shortest_path)
        cout << u << " ";
    cout << endl;

    return 0;
}
