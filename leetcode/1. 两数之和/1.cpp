class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        // 不能O(n^2)
        unordered_map<int, vector<int>> allNums;
        for (int i = 0; i < nums.size(); i++)
            allNums[nums[i]].push_back(i);
        for (int i = 0; i < nums.size(); i++)
        {
            // 取出来另一个加数对应在map里的值vector
            vector<int> a = allNums[target - nums[i]];
            if (!a.empty()) // 非空
            {
                // if(target!=2*nums[i])
                //    return {i, a[0]};
                for (int b : a)
                {
                    if (b != i)
                        return {i, b};
                }
            }
        }

        return {};
    }
};