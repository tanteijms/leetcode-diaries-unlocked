class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size(), le = 1, ri = n; // le ri是引用的次数，我们在这个范围内进行二分查找，
        // 每次与n进行比较论文数量，逐步缩小范围
        //  一定有0篇论文的引用次数大于0，则对于引用次数的二分查找，直接从1开始即可
        while (le <= ri)
        {
            int mid = le + (ri - le) / 2;  // 防止整数溢出（若写(le+ri)/2，当le ri均非常大时，可能发生）
            if (citations[n - mid] >= mid) // n-mid是从数组末尾(.end())开始数mid个，总共这mid个，
                                           // 如果n-mid这个索引对应的引用值是>=mid的，那么由单调性可知，
                                           // 右边的所有数(共mid个)一定也是>=mid的，所以就知道至少mid篇的引用数>=mid
                //  而如若缩小mid的值，那么也一定是满足的（已经至少mid个数>=mid）
                le = mid + 1; // 尝试找到一个更大的mid，由于非递减，则在右边去找

            else
                ri = mid - 1; // 当前不满足mid个数>=mid，则让mid减小去找
        }

        // 跳出循环一定ri=le-1，则答案是更小的那个。如果答案是le，那么区间应该再往右移，从而找到可能的更大的答案值
        return ri;
    }
};