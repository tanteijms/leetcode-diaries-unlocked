class Solution
{
    vector<vector<string>> ans;
    int nn;
    vector<string> path;

    bool legal(int row, int col)
    {
        for (int i = 0; i < row; i++)
        {
            if (path[i][col] == 'Q')
                return false;
        }

        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) // 斜着走
        {
            if (path[i][j] == 'Q')
                return false;
        }

        for (int i = row - 1, j = col + 1; i >= 0 && j < nn; i--, j++)
        {
            if (path[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void dfs(int i)
    {
        if (i == nn)
        {
            ans.emplace_back(path);
            return;
        }

        for (int j = 0; j < nn; j++)
        {
            if (legal(i, j))
            {
                path[i][j] = 'Q';
                dfs(i + 1);
                path[i][j] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n)
    {
        // 返回值是不同的解法，所以本质上是三维数组
        // 每个外层vector是一种解法
        // 每个内层vector代表n * n棋盘的一行
        // 内层vector存储string，是每一行的具体内容

        nn = n;
        path.assign(nn, string(nn, '.'));

        dfs(0);

        return ans;
    }
};