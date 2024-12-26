// https://leetcode.com/problems/counting-elements

class Solution
{
  public:
    int countElements(vector<int> &arr)
    {
        unordered_set<int> s;

        for (int x : arr) {
            s.insert(x);
        }

        int ans = 0;
        for (int x : arr) {
            if (s.find(x + 1) != s.end())
                ans += 1;
        }

        return ans;
    }
};