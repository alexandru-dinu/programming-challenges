// https://leetcode.com/problems/majority-element

class Solution
{
  public:
    int majorityElement(vector<int> &nums)
    {
        // Boyer–Moore
        int maj, count = 0;

        for (int x : nums) {
            if (count == 0) {
                maj = x;
                count = 1;
            } else {
                count += (maj == x) ? 1 : -1;
            }
        }

        return maj;
    }
};