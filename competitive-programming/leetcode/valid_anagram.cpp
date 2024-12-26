// https://leetcode.com/problems/valid-anagram

class Solution
{
  public:
    bool isAnagram(string s, string t)
    {
        int count[26] = { 0 };

        for (char c : s)
            count[c - 'a']++;

        for (char c : t)
            if (--count[c - 'a'] < 0)
                return false;

        for (int i = 0; i < 26; i++)
            if (count[i])
                return false;

        return true;
    }
};