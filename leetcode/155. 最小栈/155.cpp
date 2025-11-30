class MinStack
{
    vector<pair<int, int>> ms;

public:
    MinStack()
    {
    }

    void push(int val)
    {
        int n = ms.size();
        if (n == 0)
        {
            ms.emplace_back(val, val);
        }
        else
        {
            int minVal = min(val, ms[n - 1].second);
            ms.emplace_back(val, minVal);
        }
    }

    void pop()
    {
        ms.pop_back();
    }

    int top()
    {
        return ms[ms.size() - 1].first;
    }

    int getMin()
    {
        return ms[ms.size() - 1].second;
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