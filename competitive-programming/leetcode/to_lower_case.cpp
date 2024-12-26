// https://leetcode.com/problems/to-lower-case

class Solution
{
  public:
    string toLowerCase(string str)
    {
        for (int i = 0; i < str.length(); i++) {
            str[i] = ((char)str[i]) | 32;
        }

        return str;
    }
};