class Solution
{
    vector<vector<string>> ans;
    vector<string> path;
    string ss;
    int n;

    bool is_huiwen(string s) // 双指针判断当前子串是否是回文串
    {
        int i = 0, j = s.size() - 1;
        while (i < j)
        {
            if (s[i++] != s[j--])
                return false;
        }
        return true;
    }

    void dfs(int i, int start) // start是当前字串开始的位置
    {
        if (i == n)
        {
            ans.emplace_back(path);
            return;
        }

        // 当前，不选，那就不分割
        if (i < n - 1)
        {
            dfs(i + 1, start);
        }

        // 当前，选择，那就分割
        // 判断一下是否是回文串
        string a = ss.substr(start, i - start + 1);
        if (is_huiwen(a))
        {
            path.emplace_back(a);
            dfs(i + 1, i + 1);
            path.pop_back();
        }
    }

public:
    vector<vector<string>> partition(string s)
    {
        ss = s;
        n = s.size();
        if (s.empty())
            return {};
        dfs(0, 0);
        return ans;
    }
};