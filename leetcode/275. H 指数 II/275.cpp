class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        // citations已非降序排列
        // 要求对数时间复杂度
        int n = citations.size(), ans;
        for (int i = 0; i <= n; i++) // 可以是最多这么多个
        {
            auto lower_i = lower_bound(citations.begin(), citations.end(), i);
            if ((citations.end() - lower_i) >= i) // citation.end()指的本身就是对应索引为n的位置了，计数的时候不用+1
                ans = i;

            else
                break;
        }
        return ans; // 不是对数时间复杂度
    }
};