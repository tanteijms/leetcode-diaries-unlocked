class Solution
{
    void reverse_vector(vector<int> &a, int begin, int end)
    {
        for (int i = begin, j = end; i < j; i++, j--)
        {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }

public:
    void rotate(vector<int> &nums, int k)
    {
        k %= nums.size();
        reverse_vector(nums, 0, nums.size() - 1); // 闭区间！
        reverse_vector(nums, 0, k - 1);
        reverse_vector(nums, k, nums.size() - 1);
    }
};