class Solution
{
    static constexpr int DIRS[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    // 方向数组，0 1向右 1 0向下 0 -1向左 -1 0向上

public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> ans(m * n);
        int i = 0, j = 0, di = 0; // di用来表示当前的方向数组
        // i j等于0，从0, 0即左上角开始
        for (int k = 0; k < m * n; k++)
        {
            // 每次先添加，ij都是新的元素。添加以后对ij进行更新
            ans[k] = matrix[i][j]; // 添加后设为INT_MAX
            matrix[i][j] = INT_MAX;
            int x = i + DIRS[di][0]; // di指示当前的方向，只有在拐点才需要修改。最外圈用0和m n判断里面用INT_MAX
            int y = j + DIRS[di][1]; // 当前方向是什么，就给ij加多少来移动，对应方向数组的横和竖
            // 但是不能直接对ij进行加减，可能导致越界，因此先用x y临时变量去看，如果加上了di的方向，是否会到达边界
            // 或者是否到达已经访问过的
            // 如果是，那就对di进行更新，然后再更新i j
            if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] == INT_MAX)
                di = (di + 1) % 4; // 方向数组总共4个方向
            i += DIRS[di][0];
            j += DIRS[di][1];
        }
        return ans;
    }
};