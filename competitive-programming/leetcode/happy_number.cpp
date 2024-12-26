// https://leetcode.com/problems/happy-number

class Solution
{
  public:
    bool isHappy(int n)
    {
        int s = 0;
        unordered_set<int> prev;

        while (true) {
            while (n) {
                s += pow((n % 10), 2);
                n /= 10;
            }
            if (s == 1)
                return true;

            if (prev.find(s) != prev.end())
                return false;

            n = s;
            prev.insert(s);
            s = 0;
        }
    }
};