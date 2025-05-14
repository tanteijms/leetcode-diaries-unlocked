class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        int n = nums.size(), le = 0, ri = n - 2;
        while (le <= ri)
        {
            int mid = le + (ri - le) / 2;
            if (nums[mid] < nums[n - 1])
                ri = mid - 1;
            else
                le = mid + 1;
        }
        return nums[le]; // 当le=ri=mid时，一定是nums[mid]<nums[n-1]，
        // 所以ri会=le-1，这时候le是最小值
    }
};