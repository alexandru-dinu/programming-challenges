// https://leetcode.com/problems/excel-sheet-column-title

class Solution
{
  public:
    string convertToTitle(int n)
    {
        string out;

        while (n > 0) {
            char c = (char)(65 + (n - 1) % 26);
            out.push_back(c);
            n = (n - 1) / 26;
        }

        std::reverse(out.begin(), out.end());

        return out;
    }
};