class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int len = nums.size(), le = 0, sum = 0, ans = -1;
        int target = reduce(nums.begin(), nums.end()) - x;
        if (target < 0)
            return -1;

        for (int ri = 0; ri < len; ri++)
        {
            sum += nums[ri];
            while (sum > target)
                sum -= nums[le++];
            if (sum == target)
                ans = max(ans, ri - le + 1);
        }

        return ans >= 0 ? len - ans : -1;
    }
};