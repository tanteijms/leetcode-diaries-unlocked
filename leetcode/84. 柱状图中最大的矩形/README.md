# [84. 柱状图中最大的矩形](https://leetcode.cn/problems/largest-rectangle-in-histogram/)



## 题目

给定 *n* 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。

 

**示例 1:**

![img](./assets/histogram.jpg)

```
输入：heights = [2,1,5,6,2,3]
输出：10
解释：最大的矩形为图中红色区域，面积为 10
```

**示例 2：**

![img](./assets/histogram-1.jpg)

```
输入： heights = [2,4]
输出： 4
```

 

**提示：**

- $1 <= heights.length <=10^5$
- $0 <= heights[i] <= 10^4$



## 题解

```cpp
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
```



## points

1. 单调栈，接雨水类似

   以一个为基准，看左右两边比自己矮的，找到第一个比自己矮的，这样来看宽度，高度就是自身。

   从自身向左右扩展

2. 记录左右第一个比他小(大也可以)的，就用单调栈

3. 求右边第一个小的，单调递减的栈。大则递增

4. 栈里存下标

5. 计算结果的时候：当前遍历到的元素比栈顶元素小，就弹出栈顶，然后根据下标进行一次计算结果

6. 首尾+0，保证进入计算环节



review

1. 维护一个单调递减的栈，每次取heights的新元素的时候，和栈顶进行比较。如果是相同的元素，那么就替换成最新的

   如果当前元素比栈顶的要大，那就入栈，维护递减

   如果当前元素比栈顶的要小，那么就进入计算的环节：当前元素为最右，栈顶元素为中间，当作矩形的高度；栈里的下一个元素是最左。最左和最右两个维护了如果以当前中间为矩形的高度的话，这个矩形的宽度最大是多少，是right-left-1，注意是-1，因为当前的left和right的高度都已经比中间的要小，因此不能算作矩形面积的一部分

2. heights的前后都要加上0，这样方便做判断。否则：1. 若heights元素本身递减，那么一个个遍历的时候，都是直接顺序入栈了，不会走到计算结果的那一步。

   2. 若heights元素本身递增，那么每一次栈里都只有一个元素，这样有left和mid，但是弹栈以后栈就空了，找不到right，无法进行有效的宽度计算。因此设置一个0哨兵

3. 对于result，初始应当设置为0，不能INT_MIN。因为假设输入的heights是一个元素，0，那么这种情况下，填充首位的0以后，heights是：0,0,0。这样的话一直都走第二种情况，即当前元素和栈顶元素相同。无法走到计算结果的那一步。因此不如直接把result的值设置为0，然后直接输出面积为0。