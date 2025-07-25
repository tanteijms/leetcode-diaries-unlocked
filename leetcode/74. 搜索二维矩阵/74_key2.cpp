class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0, j = n - 1;
        while (i < m && j >= 0)
        {
            int a = matrix[i][j];
            if (a > target)
                j--;
            else if (a < target)
                i++;
            else
                return true;
        }
        return false;
    }
};