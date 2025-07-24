class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<int>> map;
        for (int i = 0; i < strs.size(); i++)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            map[s].push_back(i);
        }
        vector<vector<string>> ans;
        for (const auto &pair : map)
        {
            vector<string> temp;
            for (int i : pair.second)
            {
                temp.push_back(strs[i]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};