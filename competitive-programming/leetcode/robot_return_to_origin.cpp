// https://leetcode.com/problems/robot-return-to-origin

class Solution
{
  public:
    bool judgeCircle(string moves)
    {
        int count = 0;

        for (char c : moves) {
            if (c == 'L' || c == 'D')
                count -= 1;
            else
                count += 1;
        }

        return count == 0;
    }
};