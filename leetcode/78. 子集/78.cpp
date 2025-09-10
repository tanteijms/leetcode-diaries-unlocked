class Solution
{
    vector<vector<int>> ans;
    int n;
    vector<int> path;
    vector<int> num;

    void dfs(int i)
    {
        if (i == n)
        {
            ans.emplace_back(path);
            return;
        }
        dfs(i + 1);
        // 选（上）不选（下）两条不同路径，树的分叉
        path.emplace_back(num[i]);
        dfs(i + 1);
        path.pop_back();
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