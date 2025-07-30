class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        for (auto &p : intervals)
        {
            if (!ans.empty() && p[0] <= ans.back()[1])
                ans.back()[1] = max(ans.back()[1], p[1]);
            else
                ans.emplace_back(p);
        }
        return ans;
    }
};