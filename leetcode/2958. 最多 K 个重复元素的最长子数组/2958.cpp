class Solution
{
public:
    int maxSubarrayLength(vector<int> &nums, int k)
    {
        unordered_map<int, int> freq;

        int ans = 0, le = 0, no = 0;

        int n = nums.size();
        for (int ri = 0; ri < n; ri++)
        {
            int x = nums[ri];
            freq[x]++;

            while (freq[x] > k)
            {
                freq[nums[le]]--;
                le++;
            }

            no = ri - le + 1;
            ans = max(ans, no);
        }

        return ans;
    }
};