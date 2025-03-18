class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int len = nums.size(), ans = 0, sum0 = 0, le = 0;

        for (int ri = 0; ri < len; ri++)
        {
            if (nums[ri] == 0)
                sum0++;

            while (sum0 > k)
            {
                if (nums[le] == 0)
                    sum0--;

                le++;
            }

            ans = max(ans, ri - le + 1);
        }

        return ans;
    }
};