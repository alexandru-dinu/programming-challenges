// https://leetcode.com/problems/sort-characters-by-frequency

class Solution
{
    struct comp
    {
        unordered_map<char, int> m;

        comp()
        {}
        comp(unordered_map<char, int> &_m)
          : m(_m)
        {}

        inline bool operator()(char c1, char c2)
        {
            if (m[c1] == m[c2])
                return c1 < c2;

            return m[c1] > m[c2];
        }
    };

  public:
    string frequencySort(string s)
    {
        unordered_map<char, int> m;

        for (char c : s)
            ++m[c];

        for (auto p : m) {
            cout << p.first << ":" << p.second << "\n";
        }

        comp c(m);

        sort(s.begin(), s.end(), c);

        return s;
    }
};