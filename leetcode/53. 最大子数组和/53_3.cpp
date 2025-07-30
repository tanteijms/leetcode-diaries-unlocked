class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int ans = INT_MIN;
        int dp = 0;
        for (int a : nums)
        {
            dp = max(dp, 0) + a;
            ans = max(ans, dp);
        }
        return ans;
    }
};