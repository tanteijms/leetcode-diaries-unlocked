class Solution
{
    int getMaxIndex(vector<int> &a)
    {
        return max_element(a.begin(), a.end()) - a.begin();
    }

public:
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size();
        int le = 0, ri = m - 2;
        while (le <= ri)
        {
            int mid = le + (ri - le) / 2, maxIndex = getMaxIndex(mat[mid]);
            int a = mat[mid][maxIndex];
            if (a > mat[mid + 1][maxIndex])
                ri = mid - 1;     // 如果当前行大于后面的所有行，则峰值应该在当前行及以上的地方（找当前行最大元素）
            else              // 不会相等，因此只有> <两种情况
                le = mid + 1; // 如果当前行小于后面行，则找峰值要往下面去
        } // 退出循环，因为如果le=ri=mid的话，则会进入else，也就是le=ri+1。再由二分查找的范围是[0, m-2]，最后答案行应该是le（考虑如果峰值在m-1行，则只有le能够到达m-1）
        return {le, getMaxIndex(mat[le])};
    }
};