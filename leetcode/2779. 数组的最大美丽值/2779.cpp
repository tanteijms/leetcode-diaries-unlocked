class Solution
{
public:
    int maximumBeauty(vector<int> &nums, int k)
    {
        int len = nums.size(), ans = 0, no = 0, le = 0;

        std::sort(nums.begin(), nums.end());

        for (int ri = 0; ri < len; ri++)
        {
            int x = nums[ri];

            while (x - k > nums[le] + k)
            {
                le++;
            }

            no = ri - le + 1;

            ans = max(no, ans);
        }

        return ans;
    }
};