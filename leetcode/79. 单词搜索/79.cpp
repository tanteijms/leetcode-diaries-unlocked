class Solution
{
    vector<pair<int, int>> di = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    // 下 右 上 左

    vector<vector<char>> b;
    int m, n;
    string w;
    int nn;

    bool dfs(int i, int j, int k) // j k记录当前行列
    {
        // 本层及以后的
        // 当前字母可用，选
        if (w[i] == b[j][k])
        {
            if (i == nn - 1)
                return true; // 原来的套路是，给i+1，然后继续dfs
            // 这样的话，的确在结束的时候，递归到的新的，是ok的，恰好满足匹配
            // 但是我在遍历一个点的四个方向的时候，遇到不合法的，我直接不让他递归了
            // 因此不满足

            b[j][k] = '\0';
            for (auto a : di) // 遍历4个方向
            {
                int x = j + a.first;
                int y = k + a.second;
                if (x >= 0 && x < m && y >= 0 && y < n && b[x][y] != '\0')
                {
                    if (dfs(i + 1, x, y))
                    {
                        // 只有有真的，才更新为true
                        // 有了true以后，后面都要一路开绿灯，确保返回到第一层

                        b[j][k] = w[i];
                        return true;
                        // tag只是传递，必须从回溯递归终止的时候传上来
                    }
                }
            }
            b[j][k] = w[i];
        }

        // 不选的话默认就是false，当前字符直接跳过
        return false;
    }

public:
    bool exist(vector<vector<char>> &board, string word)
    {
        b = board;
        m = board.size();
        n = board[0].size();
        w = word;
        nn = word.size();

        // 统计word所有的字符
        unordered_map<char, int> cnt;
        for (auto &row : board)
        {
            for (char c : row)
                cnt[c]++;
        }

        unordered_map<char, int> word_cnt;
        for (char c : word)
        {
            word_cnt[c]++;
            if (word_cnt[c] > cnt[c])
                return false;
        }

        if (cnt[word.back()] > cnt[word[0]])
            reverse(word.begin(), word.end());

        if (m == 0 || n == 0 || w.empty())
            return false;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dfs(0, i, j))
                    return true;
            }
        }
        return false;
    }
};