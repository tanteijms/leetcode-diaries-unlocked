class RangeFreqQuery
{
private:
    unordered_map<int, vector<int>> index;

public:
    RangeFreqQuery(vector<int> &arr)
    {
        for (int i = 0; i < arr.size(); i++)
            index[arr[i]].push_back(i); // 在哈希表里记录当前值出现的索引位置，全部的索引都存在一个动态管理的vector里，方便后续进行二分查找
    }

    int query(int left, int right, int value)
    {
        if (!index.count(value))
            return 0;

        const vector<int> &pos = index[value]; // 把当前value所有的索引的一个序列表取出来
        auto lower = lower_bound(pos.begin(), pos.end(), left);
        auto upper = upper_bound(pos.begin(), pos.end(), right);
        return upper - lower;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */