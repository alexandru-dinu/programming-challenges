// https://leetcode.com/problems/implement-strstr

class Solution
{
  public:
    int strStr(string haystack, string needle)
    {
        int s;

        if (needle.length() == 0)
            return 0;

        for (int i = 0; i < haystack.length(); i++) {
            if (haystack[i] == needle[0]) {
                s = 0;
                for (int j = 0; j < needle.length(); j++) {
                    if (haystack[i + j] != needle[j])
                        break;
                    s += 1;
                }
                if (s == needle.length())
                    return i;
            }
        }

        return -1;
    }
};