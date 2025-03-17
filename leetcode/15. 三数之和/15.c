/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int **threeSum(int *nums, int n, int *returnSize, int **returnColumnSizes)
{
    /*returnSize是三元组的个数，returnColumnSizes是每个三元组内元素的个数，固定即为3*/
    qsort(nums, n, sizeof(int), cmp);
    int **ans = malloc(n * n * sizeof(int *));
    *returnColumnSizes = malloc(n * n * sizeof(int));
    int m = 0;

    for (int i = 0; i < n - 2; i++)
    {
        int x = nums[i];
        if (i > 0 && x == nums[i - 1])
            continue;

        if (x + nums[i + 1] + nums[i + 2] > 0)
            break;
        if (x + nums[n - 1] + nums[n - 2] < 0)
            continue;

        int left = i + 1, right = n - 1;

        while (left < right)
        {
            int sum = x + nums[left] + nums[right];

            if (sum > 0)
                right--;

            else if (sum < 0)
                left++;

            else
            {
                int *tuple = malloc(3 * sizeof(int));
                tuple[0] = x;
                tuple[1] = nums[left];
                tuple[2] = nums[right];

                ans[m] = tuple;

                (*returnColumnSizes)[m++] = 3;
            }

            for (left++; left < right && nums[left] == nums[left - 1]; left++)
                ;

            for (right--; right > left && nums[right] == nums[right + 1]; right++)
                ;
        }
    }

    *returnSize = m;
    return ans;
}
