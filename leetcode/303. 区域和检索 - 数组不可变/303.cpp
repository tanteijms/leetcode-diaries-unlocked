class NumArray
{
    vector<int> preSum;

public:
    NumArray(vector<int> &nums)
    {

        int sum = 0;
        preSum.push_back(0); // 第一个前缀和是0，用来计算如果left=0的情况
        // 只有前面保留一个0，才能计算从首个元素开始的加和
        for (int a : nums)
        {
            sum += a;
            preSum.push_back(sum);
        }
    }

    int sumRange(int left, int right)
    {
        return preSum[right + 1] - preSum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */