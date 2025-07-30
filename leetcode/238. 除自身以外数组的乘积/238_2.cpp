class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> ans(nums.size(), 1);
        int pro = 1;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            pro *= nums[i];
            ans[i + 1] = pro;
        }
        pro = 1;
        for (int i = nums.size() - 1; i > 0; i--)
        {
            pro *= nums[i];
            ans[i - 1] *= pro;
        }
        return ans;
    }
};