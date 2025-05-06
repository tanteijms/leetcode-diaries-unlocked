class Solution
{
public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int n = piles.size(), le = 1, ri = ranges::max(piles);
        if (n == h)
            return ri;
        while (le <= ri)
        {
            int mid = le + (ri - le) / 2; // 这个mid是试当前如果为mid个/h的速度，能否吃完。就是(le+ri)/2
            long long total_time = 0;
            for (int a : piles)
                total_time += (long long)(a + mid - 1) / mid;
            if (total_time > h) // 速度太慢了
                le = mid + 1;
            else // total_time<=h
                ri = mid - 1;
        }
        return le;
    }
};