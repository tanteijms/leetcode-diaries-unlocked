class Solution
{
    int n;
    vector<vector<int>> ans;
    vector<int> path;
    vector<int> num;

    void dfs(int i)
    {
        ans.emplace_back(path);
        for (int j = i; j < n; j++) // 每次从第i位开始
        // 看看是否要将nums[j]加入到path，也就是选or不选
        {
            path.emplace_back(num[j]);
            dfs(j + 1);
            path.pop_back(); // 需要恢复现场
        }
    }

public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        n = nums.size();
        num = nums;
        dfs(0);
        return ans;
    }
};