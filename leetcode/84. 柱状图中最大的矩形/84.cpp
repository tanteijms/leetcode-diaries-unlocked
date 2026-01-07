class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        stack<int> st; // 注意st里存的都是数组的小标，需要具体值的时候再去heights里取出
        st.push(0);
        heights.insert(heights.begin(), 0);
        heights.emplace_back(0);
        int result = 0;

        for (int i = 1; i <= heights.size() - 1; i++)
        {
            int a = st.top();
            if (heights[i] == heights[a])
            {
                st.pop();
                st.push(i);
            }
            else if (heights[i] > heights[a])
            {
                st.push(i);
            }
            else
            {
                int right = i;
                while (!st.empty() && heights[st.top()] > heights[i])
                {
                    int mid = st.top();
                    st.pop();
                    if (!st.empty())
                    {
                        int left = st.top();
                        int width = right - left - 1;
                        int area = heights[mid] * width;
                        result = max(area, result);
                    }
                }
                st.push(i);
            }
        }

        return result;
    }
};