class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int ans = 0, low = INT_MAX;
        for (int a : prices)
        {
            low = low > a ? a : low;
            int today = a - low;
            ans = ans < today ? today : ans;
        }
        return ans;
    }
};