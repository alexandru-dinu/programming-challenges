// https://leetcode.com/problems/add-binary

class Solution
{
  public:
    string addBinary(string a, string b)
    {
        std::string res;

        int carry = 0;
        int da, db, s;
        int ia = a.size() - 1, ib = b.size() - 1;

        while (ia >= 0 || ib >= 0 || carry == 1) {

            da = (ia >= 0) ? (a[ia--] - '0') : 0;
            db = (ib >= 0) ? (b[ib--] - '0') : 0;

            s = da ^ db ^ carry;
            carry = (carry == 1) ? (da | db) : (da & db);

            res = static_cast<char>(s + '0') + res;
        }

        return res;
    }
};