// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero

class Solution
{
  public:
    vector<int> sumZero(int n)
    {
        vector<int> xs(n, 0);

        for (int i = 0, k = 1; i < n / 2; i++, k++) {
            xs[i] = -k;
            xs[n - 1 - i] = k;
        }

        return xs;
    }
};