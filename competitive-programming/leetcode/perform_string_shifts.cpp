// https://leetcode.com/problems/perform-string-shifts

class Solution
{
  public:
    string stringShift(string s, vector<vector<int>> &shift)
    {

        int amt =
          accumulate(begin(shift), end(shift), 0, [](int acc, vector<int> p) {
              return acc + ((p[0] == 0) ? -1 : 1) * p[1];
          });

        if (amt == 0)
            return s;

        string out = s;

        int dir = (amt < 0) ? -1 : 1;
        amt = abs(amt) % s.length();

        // right rotate
        if (dir == 1)
            rotate(out.rbegin(), out.rbegin() + amt, out.rend());

        // left rotate
        if (dir == -1)
            rotate(out.begin(), out.begin() + amt, out.end());

        return out;
    }
};