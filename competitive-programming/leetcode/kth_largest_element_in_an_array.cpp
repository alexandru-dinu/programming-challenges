// https://leetcode.com/problems/kth-largest-element-in-an-array

class Solution
{
  public:
    int partition(vector<int> &arr, int l, int r)
    {
        int pivot = arr[r];
        int index = l;

        for (int i = l; i < r; i++) {
            if (arr[i] <= pivot) {
                iter_swap(arr.begin() + index, arr.begin() + i);
                index++;
            }
        }

        iter_swap(arr.begin() + index, arr.begin() + r);

        return index;
    }

    int find_kth(vector<int> &arr, int l, int r, int k)
    {
        int pos = partition(arr, l, r);

        if (pos - l == k)
            return arr[pos];

        if (pos - l > k)
            return find_kth(arr, l, pos - 1, k);

        else
            return find_kth(arr, pos + 1, r, k - pos + l - 1);
    }

    int findKthLargest(vector<int> &nums, int k)
    {
        const int n = nums.size();

        for (int i = 0; i < n; nums[i] *= -1, i++)
            ;

        return -1 * find_kth(nums, 0, n - 1, k - 1);
    }
};