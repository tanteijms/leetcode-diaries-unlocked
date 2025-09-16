class Solution
{
    vector<string> ans;
    vector<char> path;
    int nn;

    void dfs(int i, int le, int ri) // left表示前面 ( 的个数
    {
        if (i == 2 * nn)
        {
            string s(path.begin(), path.end());
            ans.emplace_back(s);
            return;
        }

        // ( 最多nn个，用left来判断
        if (le < nn)
        {
            path.emplace_back('(');
            dfs(i + 1, le + 1, ri);
            path.pop_back();
        }

        if (ri < le) // ( 要比 ) 多，才可以加 )
        {
            path.emplace_back(')');
            dfs(i + 1, le, ri + 1);
            path.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        nn = n;
        dfs(0, 0, 0);
        return ans;
    }
};