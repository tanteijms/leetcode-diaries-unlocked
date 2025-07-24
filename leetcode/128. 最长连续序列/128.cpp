class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        for (int a : s)
        {
            if (!s.count(a - 1)) // 只有非连续，才进入下面的。
            // 这样可以确保最后只是遍历set里面的所有元素，即(n)
            {
                int cur = a;
                int len = 1;
                while (s.count(cur + 1))
                {
                    cur++;
                    len++;
                }
                ans = max(ans, len);
            }
        }
        return ans;
    }
};