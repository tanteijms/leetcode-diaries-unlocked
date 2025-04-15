class Solution
{
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        long long ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            int a = nums[i];
            int target1 = upper - a, target2 = lower - a;
            // b>=lower-a(=target2), b<=upper-a(=target1)
            // 所以要在排序后的nums里，找到大于等于target2、且小于等于target1，满足这两个条件的数
            int index1 = i + 1 + distance(nums.begin() + i + 1, lower_bound(nums.begin() + i + 1, nums.end(), target2));
            int index2 = i + 1 + distance(nums.begin() + i + 1, upper_bound(nums.begin() + i + 1, nums.end(), target1)) - 1;
            // 思考二分查找的范围到底怎么确定
            ans += index2 - index1 + 1;
        }
        return ans;
    }
};