class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        // 记录一个前缀积，一个后缀积数组
        vector<int> prefix(nums.size());
        vector<int> suffix(nums.size());
        vector<int> ans(nums.size());
        int pro = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            pro *= nums[i];
            prefix[i] = pro;
        }
        pro = 1;
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            pro *= nums[i];
            suffix[i] = pro;
        }
        ans[0] = suffix[1];
        ans[nums.size() - 1] = prefix[nums.size() - 2];
        for (int i = 1; i < nums.size() - 1; i++)
            ans[i] = prefix[i - 1] * suffix[i + 1];
        return ans;
    }
};