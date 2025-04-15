// 时间复杂度O(n log n + m log n)
// 空间复杂度O(m)
class Solution
{
public:
    vector<int> successfulPairs(vector<int> &spells, vector<int> &potions, long long success)
    {
        sort(potions.begin(), potions.end());
        vector<int> pairs;
        for (int a : spells)
        {
            long long sub_success = (success + a - 1) / a; // 默认向下取整了，但这样a*sub_success可能比success要小
            // 只需要找到potions里大于等于sub_success的数的个数。已对potions排序，二分

            int index = distance(potions.begin(), lower_bound(potions.begin(), potions.end(), sub_success));
            if (index < potions.size())
                pairs.push_back(potions.size() - index);

            else
                pairs.push_back(0);
        }

        return pairs;
    }
};