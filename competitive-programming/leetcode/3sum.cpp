// https://leetcode.com/problems/3sum

class Solution
{
  public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> sols;

        if (nums.size() < 3)
            return {};

        std::sort(nums.begin(), nums.end());

        for (std::size_t i = 0; i <= nums.size() - 3; i++) {
            if (i > 0 and nums[i] <= nums[i - 1])
                continue;

            std::size_t left = i + 1, right = nums.size() - 1;

            while (left < right) {
                int a = nums[i], b = nums[left], c = nums[right];

                if (a + b + c == 0)
                    sols.push_back({ a, b, c });

                // keeping a constant, we increase left (b) in order to skip
                // duplicates
                if (b + c < -a)
                    for (int l = left; nums[l] == nums[left] && left < right;
                         left++)
                        ;

                // keeping a constant, we decrease right (b) in order to skip
                // duplicates
                else
                    for (int r = right; nums[r] == nums[right] && right > left;
                         right--)
                        ;
            }
        }

        return sols;
    }
};