#include <bits/stdc++.h>
#include <iostream>

using namespace std;

using entry_t = pair<string, int>;

vector<entry_t> top_k_words(vector<string> &words, int k)
{
    unordered_map<string, int> freqs;

    for (string word : words)
        freqs[word]++;

    vector<entry_t> aux;
    aux.reserve(freqs.size());

    for (auto it = begin(freqs); it != end(freqs); ++it)
        aux.push_back(*it);

    // can we do better than this?
    sort(begin(aux), end(aux), [](const auto &a, const auto &b) {
        if (a.second == b.second)
            return a.first < b.first;
        else
            return a.second > b.second;
    });

    vector<entry_t> res;
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

    return vector<entry_t>(aux.begin(), aux.begin() + k);
}

int main(int argc, char const *argv[])
{
    vector<string> words = { "a", "b", "b", "b", "b", "c", "d", "d", "d" };

    vector<entry_t> res = top_k_words(words, stoi(argv[1]));

    for (auto &e : res)
        cout << e.first << ": " << e.second << endl;

    return 0;
}
