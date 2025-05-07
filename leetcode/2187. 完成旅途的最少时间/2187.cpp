class Solution
{
public:
    long long minimumTime(vector<int> &time, int totalTrips)
    {
        ranges::sort(time);
        long long le = 0, ri = (long long)totalTrips * time[0]; // 最慢情况下完成
        while (le <= ri)
        {
            long long mid = le + (ri - le) / 2;
            long long this_total = 0;
            for (int a : time)
            {
                if (a <= mid)
                    this_total += mid / a;
                else
                    break;
            }
            if (this_total >= totalTrips)
                ri = mid - 1;
            else
                le = mid + 1;
        }
        return le;
    }
};