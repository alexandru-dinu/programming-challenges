// https://leetcode.com/problems/maximum-sum-circular-subarray

class Solution
{
  public:
    int maxSubarraySumCircular(vector<int> &A)
    {
        int max_eh = 0, max_sf = INT_MIN;
        int min_eh = 0, min_sf = INT_MAX;
        int sum = 0;

        for (int x : A) {
            max_eh = max(x, max_eh + x);
            max_sf = max(max_sf, max_eh);

            min_eh = min(x, min_eh + x);
            min_sf = min(min_sf, min_eh);

            sum += x;
        }

        return max_sf > 0 ? max(max_sf, sum - min_sf) : max_sf;
    }
};