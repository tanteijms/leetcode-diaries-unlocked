class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int le = 0, ri = nums.size() - 1;
        while (le < ri)
        {
            int mid = le + (ri - le) / 2;
            if (nums[mid] == nums[ri])
                ri--;
            else if (nums[mid] > nums[ri])
                le = mid + 1;
            else
                ri = mid; // 若当前mid已经指向最小值，则ri应移动到包含mid的区间
        } // 因为设置le<ri，则退出时恰好le=ri，都是最小值答案
        return nums[le];
    }
};