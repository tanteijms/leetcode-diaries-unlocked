class Solution
{
public:
    long long countSubarrays(vector<int> &nums, int k)
    {
        int max_val = *std::max_element(nums.begin(), nums.end()); // 可优化为：int mx = ranges::max(nums);

        int le = 0, len = nums.size(), cnt = 0;
        long ans = 0;

        for (int ri = 0; ri < len; ri++)
        {
            if (nums[ri] == max_val)
                cnt++;

            if (cnt >= k)
                ans += len - ri;

            int rec = le;

            while (cnt >= k)
            {
                if (nums[le] == max_val)
                {
                    cnt--;
                    le++;
                    break; // 当前左端点为最大值，则le++后不再给ans更新
                }

                le++;

                ans += len - ri;
            }
        }

        return ans;
    }
};