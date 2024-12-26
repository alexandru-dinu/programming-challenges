// https://leetcode.com/problems/plus-one

class Solution
{
  public:
    vector<int> plusOne(vector<int> &digits)
    {
        int n = digits.size();
        int i = n - 1;

        digits[i] = (digits[i] + 1) % 10;

        while (digits[i] == 0) {
            if (i == 0) {
                digits.insert(digits.begin(), 1);
                break;
            }

            i--;
            digits[i] = (digits[i] + 1) % 10;
        }

        return digits;
    }
};