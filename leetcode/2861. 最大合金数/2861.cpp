class Solution
{
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>> &composition, vector<int> &stock, vector<int> &cost)
    {
        int le = 1, ri = ranges::min(stock) + budget;
        while (le <= ri)
        {
            int mid = le + (ri - le) / 2; // 这个mid就是当前的num答案，认为做mid份合金
            int flag = 0;
            for (int i = 0; i < k; i++) // 遍历每台机器，看看有没有符合答案的机器
            {
                long long total_cost = 0;
                for (int j = 0; j < n; j++) // 计算所有的金属，够了不管，
                // 不够的看看加起来，总预算是否能够cover
                {
                    long long need = (long long)mid * composition[i][j]; // need是在当前i机器上制造mid份合金需要j金属的个数
                    if (need > stock[j])
                        total_cost += (long long)(need - stock[j]) * cost[j];
                }
                if (total_cost <= budget) // 找到一台机器，能够做完num份合金，
                // 则可以直接退出
                {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1) // 当前mid是可以完成的，
                           // 那么所有小于mid的合金份数，都是可以做完的。所以可以尝试比mid更大的值
                le = mid + 1;
            else // 当前mid设置得过于大了，需要向小调整
                ri = mid - 1;
        }
        return ri; // 最后结果是ri+1=le，满足题意的应该是le==ri==mid时，
        // 这时候由于想要寻求更大的mid值，则le=mid+1=ri+1，则le不满足提示，答案是ri
    }
};