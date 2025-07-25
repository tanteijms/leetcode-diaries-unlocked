class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> prefixCnt;
        prefixCnt[0] = 1; // sum=0前缀和初始值
        int sum = 0, ans = 0;
        for (int a : nums)
        {
            sum += a;
            if (prefixCnt.count(sum - k))
                ans += prefixCnt[sum - k];
            prefixCnt[sum]++;
        }
        return ans;
    }
};