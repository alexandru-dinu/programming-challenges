// https://leetcode.com/problems/fizz-buzz

class Solution
{
  public:
    using tag_t = std::pair<int, string>;
    const std::vector<tag_t> m_tags{ std::make_pair(3, "Fizz"),
                                     std::make_pair(5, "Buzz") };

    std::string fb(int x)
    {
        std::string out = "";

        for (auto const &t : m_tags)
            if (x % t.first == 0)
                out += t.second;

        return out.empty() ? to_string(x) : out;
    }
    vector<string> fizzBuzz(int n)
    {
        std::vector<std::string> xs(n);

        for (int i = 1; i <= n; i++)
            xs[i - 1] = fb(i);

        return xs;
    }
};