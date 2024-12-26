// https://leetcode.com/problems/unique-number-of-occurrences

class Solution
{
  public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        int n = arr.size();

        if (n == 1)
            return true;
        if (n == 2)
            return arr[0] == arr[1];

        sort(begin(arr), end(arr));

        unordered_set<int> occ;
        int cur = arr[0];
        int cur_cnt = 1;

        for (int i = 1; i < n; i++) {
            if (arr[i] == cur) {
                ++cur_cnt;
            } else {
                if (occ.find(cur_cnt) != occ.end())
                    return false;

                occ.insert(cur_cnt);
                cur_cnt = 1;
                cur = arr[i];
            }
        }

        return true;
    }
};