class Solution
{
public:
    int searchInsert(vector<int> &nums, int target)
    {
        int le = 0, ri = nums.size() - 1;
        while (le <= ri)
        {
            int mid = le + (ri - le) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > target)
                ri = mid - 1;
            else // nums[mid]<target
                le = mid + 1;
        }
        // 退出循环的前一刻：le=ri=mid，若=，就是le
        // 若> 也应该刚好插入到这个位置，ri--了，则是le
        // 若< 说明小了，要插入到下一个位置，刚好le++了，则直接就是le
        return le;
    }
};