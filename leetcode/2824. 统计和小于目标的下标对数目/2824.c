int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b; // 数组递增排序
}

int countPairs(int *nums, int numsSize, int target)
{
    qsort(nums, numsSize, sizeof(int), cmp);

    int n = 0;
    //-1 1 2 3 1→-1 1 1 2 3
    //-5 -4 -10 7→-10 -5 -4 7  tar=14
    for (int i = 0; i < numsSize - 1; i++) // 进行到倒数第二个数即可
    {
        int x = nums[i];

        /*if (i > 0 && x == nums[i - 1]) // 可以重复，不用舍去
            continue;*/

        if (x + nums[i + 1] >= target) // 当前x与最小的数加起来都会>=target，说明已结束，后面再遍历，只会越来越大
            break;

        for (int right = numsSize - 1; right > i; right--)
        {
            if (x + nums[right] < target)
            {
                n += right - i;
                break;
            }
        }
    }

    return n;
}