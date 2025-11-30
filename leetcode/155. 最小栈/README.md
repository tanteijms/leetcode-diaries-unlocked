# [155. 最小栈](https://leetcode.cn/problems/min-stack/)



## 题目

设计一个支持 `push` ，`pop` ，`top` 操作，并能在常数时间内检索到最小元素的栈。

实现 `MinStack` 类:

- `MinStack()` 初始化堆栈对象。
- `void push(int val)` 将元素val推入堆栈。
- `void pop()` 删除堆栈顶部的元素。
- `int top()` 获取堆栈顶部的元素。
- `int getMin()` 获取堆栈中的最小元素。

 

**示例 1:**

```
输入：
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

输出：
[null,null,null,null,-3,null,0,-2]

解释：
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
```

 

**提示：**

- $-2^31 <= val <= 2^31 - 1$
- `pop`、`top` 和 `getMin` 操作总是在 **非空栈** 上调用
- `push`, `pop`, `top`, and `getMin`最多被调用 $3 * 10^4$ 次



## 题解

```cpp
class MinStack {
    vector<pair<int, int>> ms;

public:
    MinStack() {

    }
    
    void push(int val) {
        int n = ms.size();
        if(n == 0) {
            ms.emplace_back(val, val);
        } else {
            int minVal = min(val, ms[n-1].second);
            ms.emplace_back(val, minVal);
        }
    }
    
    void pop() {
        ms.pop_back();
    }
    
    int top() {
        return ms[ms.size()-1].first;
    }
    
    int getMin() {
        return ms[ms.size()-1].second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
```



## points

1. vector<pair<>>  如果是 push_back()  要{val1, val2}

   如果是 emplace_back，不需要{}，直接 emplace_back(val1, val2)。因为是直接原地构造，直接传入构造函数的参数即可。如果传的是{}，其实是一个匿名的 pair 对象

2. 这个题还可以用 stack 来，重点是可以多次复用 getMin()函数，这个直接返回 .top.second 即可，然后其他的比如 push 的时候，可以直接 emplace(val, min(getMin(), val))