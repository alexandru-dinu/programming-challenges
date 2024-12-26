// https://leetcode.com/problems/sort-an-array

class Solution
{
  public:
    vector<int> sortArray(vector<int> &nums)
    {

        if (nums.size() <= 1)
            return nums;

        int mid = nums.size() / 2;

        vector<int> left(nums.begin(), nums.begin() + mid);
        vector<int> right(nums.begin() + mid, nums.end());

        vector<int> sleft = sortArray(left);
        vector<int> sright = sortArray(right);

        return merge(sleft, sright);
    }

    vector<int> merge(vector<int> &xs, vector<int> &ys)
    {
        vector<int> out(xs.size() + ys.size(), 0);

        int i = 0, j = 0, k = 0;

        while (i < xs.size() && j < ys.size())
            out[k++] = (xs[i] <= ys[j]) ? xs[i++] : ys[j++];

        while (i < xs.size())
            out[k++] = xs[i++];

        while (j < ys.size())
            out[k++] = ys[j++];

        return out;
    }

    void print(vector<int> &xs)
    {
        std::cout << xs.size() << ": ";
        for (int c : xs) {
            std::cout << c << " ";
        }
        std::cout << "\n";
    }
};