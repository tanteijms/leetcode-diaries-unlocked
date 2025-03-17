/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *twoSum(int *numbers, int numbersSize, int target, int *returnSize)
{
    int i = 0, j = numbersSize - 1;
    for (; i != j;)
    {
        if (numbersSize == 0)
        {
            break;
        }

        else if (numbers[i] + numbers[j] > target)
        {
            j--;
        }

        else if (numbers[i] + numbers[j] < target)
        {
            i++;
        }

        else
        {
            *returnSize = 2;
            returnSize = (int *)malloc(2 * sizeof(int));
            returnSize[0] = i + 1;
            returnSize[1] = j + 1;

            return returnSize;
        }
    }

    *returnSize = 0;
    return NULL;
}