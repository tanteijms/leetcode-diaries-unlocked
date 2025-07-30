class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        vector<int> preSum;
        preSum.push_back(0);
        int ans = INT_MIN, min = INT_MAX, sum = 0; // 前缀和第0号元素为0，则min直接设置为0
        // 问题：min的初始化没有做好
        // 解决：min初始化就为INT_MAX。需要注意的一点是min的判断要在更新sum以前
        // 因为本题存在正负数，因此不能出现min等于自身的情况，这会导致自身-自身=0
        // 这是与买卖股票不同的一点，股价只可能是正的
        for (int a : nums)
        {
            min = sum < min ? sum : min;
            sum += a;
            preSum.push_back(sum);
            int temp = sum - min;
            ans = temp > ans ? temp : ans;
        }
        return ans;
    }
};