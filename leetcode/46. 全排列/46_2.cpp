class Solution
{
    int n;
    vector<vector<int>> ans;
    vector<int> path, on_path;

    void dfs(int i, vector<int> nums)
    {
        if (i == n)
        {
            ans.emplace_back(path);
            return;
        }

        for (int j = 0; j < n; j++)
        {
            if (!on_path[j])
            {
                path[i] = nums[j];
                on_path[j] = true;
                dfs(i + 1, nums);
                on_path[j] = false;
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        n = nums.size();
        path.resize(n);
        on_path.resize(n);

        dfs(0, nums);
        return ans;
    }
};