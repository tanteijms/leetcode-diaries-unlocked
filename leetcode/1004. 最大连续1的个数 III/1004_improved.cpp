class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int len = nums.size(), ans = 0, sum0 = 0, le = 0;

        for (int ri = 0; ri < len; ri++)
        {
            /*if (nums[ri] == 0)
                sum0++;*/
            sum0 += 1 - nums[ri]; // 当为0时，令sum0++；当为1时，sum0不变

            while (sum0 > k)
            {
                /*if (nums[le] == 0)
                    sum0--;*/

                sum0 -= 1 - nums[le]; // 与上面同理
                le++;
            }

            ans = max(ans, ri - le + 1);
        }

        return ans;
    }
};