int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int threeSumClosest(int *nums, int numsSize, int target)
{
    qsort(nums, numsSize, sizeof(int), cmp);

    int close = nums[0] + nums[1] + nums[2]; // 记录当前最接近的和

    int diff = 100000; // 记录这个差值，先设为无穷大

    for (int i = 0; i < numsSize - 2; i++) // 外层循环遍历到倒数第三个数即可
    {
        int x = nums[i];

        if (i > 0 && x == nums[i - 1])
            continue; // 去掉重复的

        int s = x + nums[i + 1] + nums[i + 2];
        if (s > target) // 递增序列，后面的只会越来越大，则可以停止遍历i
        {
            if (diff > s - target) // 此时得到更小的close，则可以直接返回
            {
                // 无需更新diff
                close = s;
            }
            break;
        }

        s = x + nums[numsSize - 1] + nums[numsSize - 2];
        if (s < target) // x与最大的两个数都会小于，而且最大的两个数是双指针遍历过程能得到的最大值，也即现在的一定是当前x最接近target的值，则continue，继续遍历后面的x
        {
            if (diff > target - s)
            {
                diff = target - s;
                close = s;
            }
            continue;
        }

        int j = i + 1, k = numsSize - 1; // 创建相向双指针

        while (j < k)
        {
            s = x + nums[j] + nums[k];
            if (s == target)
                return target;

            else if (s < target)
            {
                if (target - s < diff)
                {
                    diff = target - s;
                    close = s;
                }
                j++;
            }

            else // s > target
            {
                if (s - target < diff)
                {
                    diff = s - target;
                    close = s;
                }
                k--;
            }
        }
    }

    return close;
}