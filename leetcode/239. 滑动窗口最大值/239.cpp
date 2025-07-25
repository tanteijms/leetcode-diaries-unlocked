class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        vector<int> ans;
        deque<int> q;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            // 入
            while (!q.empty() && nums[q.back()] <= nums[i])
            {
                // =的时候也要移除，确保是最新的
                q.pop_back();
            }
            q.push_back(i); // 记录的是索引值。因为前后顺序是重要的，光记录值没有用

            // 出
            if (i - q.front() >= k) // 说明此时队头已经出了k的窗口范围了
                q.pop_front();

            // 记录答案
            if (i >= k - 1) // 一开始在k-1号元素的时候才开始记录答案
                ans.push_back(nums[q.front()]);
        }
        return ans;
    }
};