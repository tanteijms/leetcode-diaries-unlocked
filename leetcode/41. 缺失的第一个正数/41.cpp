class Solution
{
public:
    int firstMissingPositive(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            while (1 <= nums[i] && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]) // -1确保实际与数组一致，开始不同，1和0
            {
                int a = nums[i] - 1;
                swap(nums[i], nums[a]);
            }
        }
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != i + 1)
                return i + 1;
        }
        return nums.size() + 1;
    }
};