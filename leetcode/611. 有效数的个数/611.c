int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int triangleNumber(int *nums, int numsSize)
{
    qsort(nums, numsSize, sizeof(int), cmp);

    int s = 0;

    for (int i = numsSize - 1; i > 1; i--)
    {
        int x = nums[i];

        if (nums[0] + nums[1] > x) // 因为0 1号元素加起来已经大于当前x，那么任意大于0 1的两个数加起来＞ 0 + 1 ＞x＞比x小的任意数（大于前面“任意大于0 1的两个数”）
        {                          // 则从0 1开始到当前第i号元素任意组合，都可以组成三角形。这总共有i+1个
            // 是一个C(i+1,3)
            s += (i + 1) * i * (i - 1) / 6;
            break; // 外层循环直接停止
        }

        if (nums[i - 1] + nums[i - 2] <= x) // 当前比x小的最大的两个数，加起来都≤x，则该第i号元素x不能与前面的数构成三角形，故continue
        {
            continue;
        }

        int j = 0, k = i - 1; // 倒序遍历x，则j从0，k从i-1（当前要遍历范围的一头一尾）

        while (j < k)
        {
            if (nums[j] + nums[k] > x) // 若不能构成三角形，说明x过大，则令左指针j增大。当增大到恰好＞的时候，则nums[k],x和j到k-1之间的数都可以构成三角形。是k-j个
            {
                s += k - j;
                k--; // 把k减小，之后再让j增大，最终完成j k前后遍历完毕比x小的数
            }

            else
                j++;
        }
    }

    return s;
}