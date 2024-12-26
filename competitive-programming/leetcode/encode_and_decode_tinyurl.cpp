// https://leetcode.com/problems/encode-and-decode-tinyurl

class Solution
{
  public:
    const string sigma =
      "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const int len_sigma = 62;

    map<int, string> db; // index -> long
    int index = 0;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        string shortUrl = "";

        index++;

        int c = index;
        while (c > 0) {
            shortUrl = sigma[c % len_sigma] + shortUrl;
            c /= len_sigma;
        }

        db[index] = longUrl;

        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        int c = 0;

        for (int i = shortUrl.size() - 1; i >= 0; i--) {
            int p = static_cast<int>(pow(len_sigma, shortUrl.size() - 1 - i));
            int j = static_cast<int>(sigma.find(shortUrl[i]));

            c += p * j;
        }

        if (db.find(c) != db.end())
            return db[c];
        else
            return "";
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));