class Solution
{
    vector<vector<int>> ans;
    vector<int> path;
    vector<int> can;
    int n;
    int t;

    void dfs(int i, int sum)
    {
        // 终止条件1，找到了目标和，就立马加入path，并返回此次回溯
        // 因为数值均为正，后面找到一定超过当前值
        if (sum == t)
        {
            ans.emplace_back(path);
            return;
        }

        // 终止条件2：越界，或超出目标值，及时停止回溯，当前分支没有结果
        if (i == n || sum > t)
            return;

        // 选当前i
        path.emplace_back(can[i]);
        dfs(i, sum + can[i]); // 因为允许重复选择，所以当前i不增加
        path.pop_back();

        // 不选当前i
        dfs(i + 1, sum);
    }

public:
    vector<vector<int>>
    combinationSum(vector<int> &candidates, int target)
    {
        n = candidates.size();
        t = target;
        can = candidates;
        dfs(0, 0);
        return ans;
    }
};