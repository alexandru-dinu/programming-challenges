// https://leetcode.com/problems/k-closest-points-to-origin

struct comp
{
    bool operator()(const vector<int> &p1, const vector<int> &p2)
    {
        long long d1 = p1[0] * p1[0] + p1[1] * p1[1];
        long long d2 = p2[0] * p2[0] + p2[1] * p2[1];
        return d1 < d2;
    }
};

class Solution
{
  public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int K)
    {
        nth_element(points.begin(), points.begin() + K, points.end(), comp());
        vector<vector<int>> ans(points.begin(), points.begin() + K);
        return ans;
    }
};