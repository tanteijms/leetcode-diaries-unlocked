int minSubArrayLen(int target, int *nu, int n)
{
    int ans = n + 1;                 // nums最多100000个
    int le = 0, max = nu[0], no = 0; // no初始时直接将ri所在的第一个元素加上

    /*for (int i = 1; i < n; i++)//反正总得遍历一遍，那还是不要这一次的判断了吧。除非有更快的方法可以得到数组的最大值
        max = max < nu[i] ? nu[i] : max;

    if (n * max < target)
        return 0;*/

    for (int ri = 0; ri < n; ri++)
    {
        int x = nu[ri];
        no += x;

        while (no - nu[le] >= target) // 若le==ri，则no=0，而nu是正整数数组
        {
            no -= nu[le];
            le++;
        }

        if (no >= target)
            ans = ans > ri - le + 1 ? ri - le + 1 : ans;
    }

    return ans == n + 1 ? 0 : ans;
}