class Solution
{
    int n;
    vector<vector<int>> ans;
    vector<int> path;
    set<int> s;

    void dfs(int i, set<int> s)
    {
        if (i == n)
        {
            ans.emplace_back(path);
            return;
        }

        for (int x : s)
        {
            path[i] = x;
            set<int> next_s = s;
            next_s.erase(x);
            dfs(i + 1, next_s);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        n = nums.size();
        path.resize(n); // 如果在全局变量去(n)，因为n未初始化，会出错
        s = set<int>(nums.begin(), nums.end());
        dfs(0, s);
        return ans;
    }
};