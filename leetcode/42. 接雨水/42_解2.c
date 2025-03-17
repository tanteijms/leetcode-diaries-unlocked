int trap(int *h, int n)
{
    int ans = 0;
    int le = 0, ri = n - 1;
    int pre_max = 0;
    int suf_max = 0;

    while (le <= ri) // 当两指针相遇时，仍有最后一个木桶未计算
    {
        pre_max = h[le] > pre_max ? h[le] : pre_max;
        suf_max = h[ri] > suf_max ? h[ri] : suf_max;

        if (pre_max < suf_max)
        {
            ans += pre_max - h[le];
            le++;
        }

        else
        {
            ans += suf_max - h[ri];
            ri--;
        }
    }

    return ans;
}