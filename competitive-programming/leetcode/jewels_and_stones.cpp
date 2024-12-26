// https://leetcode.com/problems/jewels-and-stones

class Solution
{
  public:
    int numJewelsInStones(string J, string S)
    {
        set<char> j(begin(J), end(J));

        return accumulate(begin(S), end(S), 0, [&j](int acc, char c) {
            return acc + (j.find(c) != j.end());
        });
    }
};