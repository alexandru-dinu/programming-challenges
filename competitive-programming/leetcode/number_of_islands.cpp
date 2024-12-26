// https://leetcode.com/problems/number-of-islands

class Solution
{
  public:
    int numIslands(vector<vector<char>> &grid)
    {
        if (grid.empty())
            return 0;

        int ans = 0;
        int H = grid.size();
        int W = grid[0].size();

        auto inside = [H, W](int r, int c) {
            return 0 <= r and r < H and 0 <= c and c < W;
        };

        const vector<pair<int, int>> dirs = {
            { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 }
        };

        for (int r = 0; r < H; ++r) {
            for (int c = 0; c < W; ++c) {
                if (grid[r][c] == '0')
                    continue;

                ++ans; // new island

                // do bfs from here
                queue<pair<int, int>> q;
                q.push({ r, c });
                grid[r][c] = '0'; // mark visited

                while (!q.empty()) {
                    auto p = q.front();
                    q.pop();

                    for (auto d : dirs) {
                        int nr = p.first + d.first;
                        int nc = p.second + d.second;

                        if (inside(nr, nc) and grid[nr][nc] == '1') {
                            q.push({ nr, nc });
                            grid[nr][nc] = '0';
                        }
                    }
                }
            }
        }

        return ans;
    }
};