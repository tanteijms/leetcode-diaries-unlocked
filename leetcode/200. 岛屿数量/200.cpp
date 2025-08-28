class Solution
{
    int m, n;

    void dfs(int i, int j, vector<vector<char>> &grid)
    {
        // 终止递归的条件是越界，或者触及到了边界（即当前不是岛屿了）
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != '1')
            return;
        // 不为空，是有效访问，则标记，防止反复递归
        grid[i][j] = '2';
        // 下面递归四个方向，比二叉树多
        dfs(i, j - 1, grid);
        dfs(i, j + 1, grid);
        dfs(i - 1, j, grid);
        dfs(i + 1, j, grid);
    }

public:
    int numIslands(vector<vector<char>> &grid)
    {
        m = grid.size();
        n = grid[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1') // 发现一个新岛屿，开始递归
                {
                    dfs(i, j, grid);
                    ans++;
                }
            }
        }
        return ans;
    }
};