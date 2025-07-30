class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        k %= nums.size();
        reverse(nums.begin(), nums.end()); // 左闭右开
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};