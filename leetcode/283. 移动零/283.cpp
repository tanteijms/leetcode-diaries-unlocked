class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        // 注意保持非零元素的相对顺序
        int j = 0;
        for (int &x : nums) // 引用x，因为要修改值
        {
            if (x)
                swap(x, nums[j++]);
        }
    }
};