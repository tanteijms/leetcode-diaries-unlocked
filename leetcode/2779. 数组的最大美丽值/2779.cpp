class Solution
{
public:
    int maximumBeauty(vector<int> &nums, int k)
    {
        int len = nums.size(), ans = 0;

        std::sort(nums.begin(), nums.end());

        unordered_map freq;

        for (int x : nums)
        {
            if (x < k)
            {
                for (int i = 0; i <= x + k; i++)
                    freq[i]++;
            }

            else // x>=k
            {
                for (int i = x - k)
            }
        }

        return ans;
    }
};