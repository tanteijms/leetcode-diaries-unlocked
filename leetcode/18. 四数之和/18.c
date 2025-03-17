/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int **fourSum(int *nums, int numsSize, int target, int *returnSize, int **returnColumnSizes)
{
    qsort(nums, numsSize, sizeof(int), cmp);

    *returnSize = 0;
    *returnColumnSizes = (int *)malloc(numsSize * numsSize * sizeof(int));
    int **ans = (int **)malloc(numsSize * numsSize * sizeof(int));
    int m = 0;
    for (int i = 0; i < numsSize - 3; i++)
    {
        int x = nums[i];

        if (i > 0 && nums[i - 1] == x)
            continue;

        long b1 = (long)x + nums[numsSize - 1] + nums[numsSize - 2] + nums[numsSize - 3];
        if (b1 < target)
            continue; // 令i继续增大，仍有可能满足target

        long b2 = (long)x + nums[i + 1] + nums[i + 2] + nums[i + 3];
        if (b2 > target)
            break;

        for (int j = i + 1; j < numsSize - 2; j++)
        {
            int y = nums[j];
            if (j > i + 1 && nums[j - 1] == y)
                continue;

            long a1 = (long)x + y + nums[numsSize - 1] + nums[numsSize - 2];
            if (a1 < target)
                continue; // 令j继续增大，仍有可能满足target

            long a2 = (long)x + y + nums[j + 1] + nums[j + 2];
            if (a2 > target)
                break;

            int le = j + 1, ri = numsSize - 1;

            while (le < ri)
            {
                long s = (long)x + y + nums[le] + nums[ri];

                if (s > target)
                    ri--;

                else if (s < target)
                    le++;

                else // s==target
                {
                    int *four = (int *)malloc(4 * sizeof(int));
                    four[0] = x;
                    four[1] = y;
                    four[2] = nums[le];
                    four[3] = nums[ri];

                    ans[m] = four;

                    (*returnColumnSizes)[m++] = 4;

                    for (le++; le < ri && nums[le] == nums[le - 1]; le++)
                        ;
                    for (ri--; ri > le && nums[ri] == nums[ri + 1]; ri--)
                        ;
                }
            }
        }
    }

    *returnSize = m;
    return ans;
}