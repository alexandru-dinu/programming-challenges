// https://leetcode.com/problems/implement-rand10-using-rand7

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution
{
  public:
    int rand10()
    {
        // idea: use [1,40], discard and repeat for [41,49]
        int n = (rand7() - 1) * 7 + rand7();
        return (n <= 40) ? (1 + n % 10) : rand10();
    }
};