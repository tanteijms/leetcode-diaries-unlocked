class Solution
{
public:
    long long countSubarrays(vector<int> &nums, long long k)
    {
        long len = nums.size(), sum = 0, ans = 0;
        int le = 0;

        for (int ri = 0; ri < len; ri++)
        {
            if (nums[ri] >= k)
            {
                le = ri + 1;
                sum = 0;
                continue;
            }

            sum += nums[ri];

            while (sum * (ri - le + 1) >= k)
                sum -= nums[le++];

            ans += ri - le + 1;
        }

        return ans;
    }
};