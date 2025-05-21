class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int n = nums.size(), le = 0, ri = n - 1, end = nums[ri];
        while (le <= ri)
        {
            int mid = le + (ri - le) / 2;
            int x = nums[mid], is_blue = 0;
            if (x > end)
            {
                if (target > end && x >= target) // 两段递增，x和target都在第一段，
                // 都比end大。且这时候需要满足x是大于target的，这样由递增，则x在target右边
                    is_blue = 1;
            }
            else
            {
                if (target > end)
                    is_blue = 1;
                else
                {
                    if (x >= target)
                        is_blue = 1;
                }
            }

            if (is_blue) // 这种情况下染蓝色
                ri = mid - 1;

            else
                le = mid + 1;
        }
        if (le == n || target != nums[le])
            return -1;
        return le;
        // 最后ri=le=mid的时候，这时候就是target。之后会染蓝，则ri到了le-1。则答案是le
        // 但如果最后没有答案，要返回-1。什么情况呢：1.target比最大的数还大（或小  小）
        // 2.target在区间范围内，但是不存在
        // 为了跳出循环，最后肯定是le=ri+1，应该le恰好是nums.size()
    }
};