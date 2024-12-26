// https://leetcode.com/problems/complex-number-multiplication

class Solution
{
  public:
    std::pair<int, int> parse(string a)
    {
        std::pair<int, int> z;

        auto sign = a.find('+');

        z.first = std::stoi(a.substr(0, sign));
        z.second = std::stoi(a.substr(sign + 1, a.size() - sign - 2));

        return z;
    }

    string complexNumberMultiply(string a, string b)
    {
        std::pair<int, int> z1 = parse(a);
        std::pair<int, int> z2 = parse(b);

        std::pair<int, int> zres;

        zres.first = z1.first * z2.first - z1.second * z2.second;
        zres.second = z1.first * z2.second + z1.second * z2.first;

        string res = to_string(zres.first) + "+" + to_string(zres.second) + "i";

        return res;
    }
};