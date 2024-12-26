// https://leetcode.com/problems/flood-fill

class Solution
{
    using image_t = vector<vector<int>>;

  public:
    void dfs(image_t &image, int r, int c, int origColor, int newColor)
    {
        if (image[r][c] != origColor or image[r][c] == newColor)
            return;

        image[r][c] = newColor;

        const int h = image.size();
        const int w = image[0].size();
        vector<pair<int, int>> nx = {
            { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 }
        };

        for (auto &p : nx) {
            int r_ = max(0, min(h - 1, r + p.first));
            int c_ = max(0, min(w - 1, c + p.second));
            dfs(image, r_, c_, origColor, newColor);
        }
    }
    vector<vector<int>> floodFill(image_t &image, int sr, int sc, int newColor)
    {
        if (image.size() <= 1 or image[0].size() <= 1)
            return image;

        dfs(image, sr, sc, image[sr][sc], newColor);

        return image;
    }
};