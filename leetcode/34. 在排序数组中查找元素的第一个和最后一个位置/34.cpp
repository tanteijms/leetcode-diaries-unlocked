class Solution
{
public:
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> ans(2, -1);
        int start = distance(begin(), lower_bound(nums.begin(), nums.end(), target));
        if (start == nums.size() || nums[start] != target)
            return ans;
        int end = distance(begin(), lower_bound(nums.begin(), nums.end(), target + 1) - 1);
        ans[1] = start;
        ans[2] = end;
        return ans;
    }
};