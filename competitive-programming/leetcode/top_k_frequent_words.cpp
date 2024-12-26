// https://leetcode.com/problems/top-k-frequent-words

class Solution
{
    using entry_t = pair<string, int>;

  public:
    vector<string> topKFrequent(vector<string> &words, int k)
    {
        unordered_map<string, int> freqs;

        for (string word : words)
            freqs[word]++;

        vector<entry_t> aux;
        aux.reserve(freqs.size());

        for (auto it = begin(freqs); it != end(freqs); ++it)
            aux.push_back(*it);

        sort(begin(aux), end(aux), [](const auto &a, const auto &b) {
            if (a.second == b.second)
                return a.first < b.first;
            else
                return a.second > b.second;
        });

        vector<string> res;
        res.reserve(k);

        // k-distinct
        /*
        int cfreq = aux[0].second;

        for (entry_t& p : aux) {
            if (p.second < cfreq) {
                k--;
                cfreq = p.second;
            }

            if (k == 0)
                break;

            res.push_back(p.first);
        }
        */

        for (int i = 0; i < k; i++)
            res.push_back(aux[i].first);

        return res;
    }
};