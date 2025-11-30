class Solution
{
public:
    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            int a = temperatures[i];
            while (!st.empty() && a >= temperatures[st.top()])
            {
                st.pop();
            }

            if (!st.empty())
            {
                ans[i] = st.top() - i;
            }

            st.push(i);
        }
        return ans;
    }
};