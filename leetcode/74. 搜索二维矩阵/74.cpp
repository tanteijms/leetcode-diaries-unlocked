class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int le = 0, ri = m - 1;
        while (le <= ri)
        {
            int mid = le + (ri - le) / 2, a = matrix[mid][0];
            if (a > target)
                ri = mid - 1;
            else if (a < target)
                le = mid + 1;
            else
                return true;
        }
        // 当le=ri=mid时，此时会导致ri=mid-1，故答案就是ri
        // 在第ri行去继续找
        int row = ri; // 这里要对row的值进行判断，如果不在矩阵的范围内，则直接flase
        if (row < 0 || row >= m)
            return false;
        le = 0, ri = n - 1;
        while (le <= ri)
        {
            int mid = le + (ri - le) / 2, a = matrix[row][mid];
            if (a > target)
                ri = mid - 1;
            else if (a < target)
                le = mid + 1;
            else
                return true; // =target
        }
        return false;
    }
};