class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        vector<int> temp(nums.size());
        k %= nums.size();
        temp.assign(nums.end() - k, nums.end());
        for (int i = 0; i < nums.size() - k; i++)
            temp.emplace_back(nums[i]);
        nums.assign(temp.begin(),temp.end());
    }
};