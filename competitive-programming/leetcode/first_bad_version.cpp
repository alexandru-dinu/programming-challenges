// https://leetcode.com/problems/first-bad-version

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
  public:
    int firstBadVersion(int n)
    {
        int l = 1, r = n;
        int mid;
        int p = -1;

        while (l <= r) {
            mid = l + (r - l) / 2;
            if (isBadVersion(mid)) {
                p = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return p;
    }
};