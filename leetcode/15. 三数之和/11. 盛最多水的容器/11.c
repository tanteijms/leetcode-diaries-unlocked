int maxArea(int *h, int n)
{
    int le = 0, ri = n - 1;

    int ans = 0;
    while (le < ri)
    {
        int area = (ri - le) * (h[le] < h[ri] ? h[le] : h[ri]);

        ans = ans < area ? area : ans;

        h[le] > h[ri] ? ri-- : le++;
    }

    return ans;
}