class Solution
{
    vector<int> colors;
    vector<vector<int>> g;
    bool dfs(int x)
    {
        colors[x] = 1;     // 在此次dfs访问中
        for (int y : g[x]) // 从x开始找它后面的
        {
            if (colors[y] == 1 || (colors[y] == 0 && dfs(y))) // 保证未访问才能访问
                return true;
        }
        colors[x] = 2; // 处理完毕
        return false;
    }

public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
    {
        // 把课程关系初始化到图里
        g.resize(numCourses);
        for (auto &p : prerequisites)
            g[p[1]].emplace_back(p[0]); // 原本是[a,b]表示先修b，后修a
                                        // 用b->a表示先后顺序关系
        colors.resize(numCourses);

        for (int i = 0; i < numCourses; i++)
        {
            if (colors[i] == 0 && dfs(i))
                return false;
        }
        return true;
    }
};