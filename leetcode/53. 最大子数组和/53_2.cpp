class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++)
            dp[i] = max(dp[i - 1], 0) + nums[i];
        return *max_element(dp.begin(), dp.end());
        // 或ranges::max(dp)
    }
};