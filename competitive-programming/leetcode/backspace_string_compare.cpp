// https://leetcode.com/problems/backspace-string-compare

class Solution
{
  public:
    string normalize(const string &s)
    {
        int n = s.size();
        string out;

        int i = n - 1;
        int skip = 0;

        while (i >= 0) {
            if (s[i] != '#') {
                if (skip > 0)
                    skip--;
                else
                    out += s[i];
            } else
                skip++;

            i--;
        }

        return out;
    }

    bool no_extra_space(const string &s, const string &t)
    {
        int i = s.size() - 1;
        int j = t.size() - 1;
        int skip_s = 0, skip_t = 0;

        while (i >= 0 || j >= 0) {
            char cs, ct;

            while (i >= 0) {
                if (s[i] != '#') {
                    if (skip_s > 0) {
                        skip_s--;
                        i--;
                    } else {
                        cs = s[i];
                        break;
                    }
                } else {
                    skip_s++;
                    i--;
                }
            }

            while (j >= 0) {
                if (t[j] != '#') {
                    if (skip_t > 0) {
                        skip_t--;
                        j--;
                    } else {
                        ct = t[j];
                        break;
                    }
                } else {
                    skip_t++;
                    j--;
                }
            }

            if (i >= 0 and j >= 0 and cs != ct)
                return false;

            if ((i >= 0) != (j >= 0))
                return false;

            i--;
            j--;
        }

        return true;
    }

    bool backspaceCompare(string S, string T)
    {

        // extra O(M+N) space
        // return normalize(S) == normalize(T);

        // O(1) space
        return no_extra_space(S, T);
    }
};