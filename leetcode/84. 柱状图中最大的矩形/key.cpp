#include <bits/stdc++.h>
using namespace std;
// 版本一
class Solution
{
public:
    int largestRectangleArea(vector<int> &heights)
    {
        int result = 0;
        stack<int> st;
        heights.insert(heights.begin(), 0); // 数组头部加入元素0
        heights.push_back(0);               // 数组尾部加入元素0
        st.push(0);

        // 第一个元素已经入栈，从下标1开始
        for (int i = 1; i < heights.size(); i++)
        {
            if (heights[i] > heights[st.top()])
            { // 情况一
                st.push(i);
            }
            else if (heights[i] == heights[st.top()])
            {             // 情况二
                st.pop(); // 这个可以加，可以不加，效果一样，思路不同
                st.push(i);
            }
            else
            { // 情况三
                while (!st.empty() && heights[i] < heights[st.top()])
                { // 注意是while
                    int mid = st.top();
                    st.pop();
                    if (!st.empty())
                    {
                        int left = st.top();
                        int right = i;
                        int w = right - left - 1;
                        int h = heights[mid];
                        result = max(result, w * h);
                    }
                }
                st.push(i);
            }
        }
        return result;
    }
};