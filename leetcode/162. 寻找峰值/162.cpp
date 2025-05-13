class Solution
{
public:
    int findPeakElement(vector<int> &nums)
    {
        int le = 0, ri = nums.size() - 2;
        while (le <= ri)
        {
            int mid = le + (ri - le) / 2;
            if (nums[mid] < nums[mid + 1]) // 题目保证不会相等
                le = mid + 1;              // mid指向的值比mid+1的小，说明mid是在峰顶左侧的，
            // 峰顶在mid的右侧，我们要去右侧去找，所以把le=mid+1，
            // mid是在峰顶左侧的，要把mid染红色。这样，mid+1是未知的，所以去mid+1那边再确定如何染色
            else
                ri = mid - 1;
        }
        return le;
    }
};