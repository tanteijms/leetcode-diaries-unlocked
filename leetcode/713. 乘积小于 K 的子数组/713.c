int numSubarrayProductLessThanK(int *nu, int n, int k)
{
    if (k <= 1)
        return 0; // 因为都是正整数，至少为1，而要求严格小于k

    int le = 0, ans = 0, no = 1; // 乘积

    for (int ri = 0; ri < n; ri++)
    {
        no *= nu[ri];

        while (no >= k)
        {
            no /= nu[le];
            le++;
        }

        ans += ri - le + 1;
    }

    return ans;
}