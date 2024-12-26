// https://leetcode.com/problems/product-of-array-except-self

class Solution
{
  public:
    vector<int> with_extra_space(const vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, 0);

        vector<int> l(n, 1);
        l[0] = nums[0];
        for (int i = 1; i < n; i++)
            l[i] = l[i - 1] * nums[i];

        vector<int> r(n, 1);
        r[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            r[i] = r[i + 1] * nums[i];

        ans[0] = r[1];
        ans[n - 1] = l[n - 2];

        for (int i = 1; i < n - 1; i++)
            ans[i] = l[i - 1] * r[i + 1];

        return ans;
    }

    vector<int> without_extra_space(const vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);

        ans[0] = 1;
        for (int i = 1; i < n; i++)
            ans[i] = ans[i - 1] * nums[i - 1];

        int r = 1; // product of all elements to the right
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= r;
            r *= nums[i];
        }

        return ans;
    }

    vector<int> productExceptSelf(vector<int> &nums)
    {
        // return with_extra_space(nums);

        return without_extra_space(nums);
    }
};