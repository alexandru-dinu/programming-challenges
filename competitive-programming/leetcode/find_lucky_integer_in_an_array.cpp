// https://leetcode.com/problems/find-lucky-integer-in-an-array

class Solution
{
  public:
    int findLucky(vector<int> &arr)
    {
        map<int, int> m;
        for (int x : arr)
            ++m[x];

        int ans = -1;
        for (auto e : m) {
            if (e.first == e.second)
                ans = e.first;
        }

        return ans;
    }
};