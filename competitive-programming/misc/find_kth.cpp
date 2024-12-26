#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

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

int _find_kth_min(vector<int> &arr, int l, int r, int k)
{
    int pos = partition(arr, l, r);

    if (pos - l == k)
        return arr[pos];

    if (pos - l > k)
        return _find_kth_min(arr, l, pos - 1, k);

    else
        return _find_kth_min(arr, pos + 1, r, k - pos + l - 1);
}

int find_kth_min(vector<int> &nums, int k)
{
    const int n = nums.size();

    return _find_kth_min(nums, 0, n - 1, k);
}

int find_kth_max(vector<int> &nums, int k)
{
    const int n = nums.size();

    for (int i = 0; i < n; nums[i] *= -1, i++)
        ;

    return -1 * _find_kth_min(nums, 0, n - 1, k);
}

int find_kth_max2(vector<int> &nums, int k)
{
    std::nth_element(nums.begin(),
                     nums.begin() + k - 1,
                     nums.end(),
                     [](const int &i1, const int &i2) { return i2 < i1; });

    return nums[k - 1];
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << k << "min: " << find_kth_min(arr, k) << "\n";
    cout << k << "max: " << find_kth_max(arr, k) << "\n";

    return 0;
}