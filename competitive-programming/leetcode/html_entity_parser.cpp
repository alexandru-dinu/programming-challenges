// https://leetcode.com/problems/html-entity-parser

class Solution
{
  public:
    unordered_map<string, string> ENT = {
        { "&quot;", "\"" }, { "&apos;", "'" }, { "&amp;", "&" },
        { "&gt;", ">" },    { "&lt;", "<" },   { "&frasl;", "/" }
    };

    string replace_all(string str, const string &from, const string &to)
    {
        size_t start_pos = 0;
        while ((start_pos = str.find(from, start_pos)) != string::npos) {
            str.replace(start_pos, from.length(), to);
            start_pos += to.length();
        }
        return str;
    }

    string entityParser(string text)
    {
        for (auto e : ENT)
            text = replace_all(text, e.first, e.second);

        return text;
    }
};