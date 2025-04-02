class Solution
{
public:
    int maximumCount(vector<int> &nums)
    {
        int pos_index = distance(nums.begin(), lower_bound(nums.begin(), nums.end(), 1));
        int neg = distance(nums.begin(), lower_bound(nums.begin(), nums.end(), 0));
        int pos = nums.size() - pos_index;
        return max(neg, pos);
    }
};