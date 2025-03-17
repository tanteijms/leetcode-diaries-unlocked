int trap(int *h, int n)
{
    int *pre_max = (int *)calloc(n, sizeof(int));
    int *suf_max = (int *)calloc(n, sizeof(int));

    int ans = 0;
    pre_max[0] = h[0];
    suf_max[n - 1] = h[n - 1];
    for (int i = 1; i < n; i++)
        pre_max[i] = h[i] > pre_max[i - 1] ? h[i] : pre_max[i - 1];

    for (int i = n - 2; i >= 0; i--)
        suf_max[i] = h[i] > suf_max[i + 1] ? h[i] : suf_max[i + 1];

    for (int i = 0; i < n; i++)
        ans += 1 * ((pre_max[i] < suf_max[i] ? pre_max[i] : suf_max[i]) - h[i]);

    free(pre_max);
    free(suf_max);
    return ans;
}