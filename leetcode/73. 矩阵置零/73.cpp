class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        unordered_set<int> st; // 可以去重
        for (int i = 0; i < matrix.size(); i++)
        {
            int flag = 0; // 用来指示当前行是否有0
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    flag = 1;
                    st.insert(j);
                }
            }
            if (flag)
            {
                for (int j = 0; j < matrix[0].size(); j++)
                    matrix[i][j] = 0;
            }
        }
        for (int i = 0; i < matrix[0].size(); i++)
        {
            if (st.count(i))
            {
                for (int j = 0; j < matrix.size(); j++)
                    matrix[j][i] = 0;
            }
        }
    }
};