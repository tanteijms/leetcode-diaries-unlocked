class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ans;
        unordered_map<char, int> mp;
        for (char c : p)
            mp[c]++;
        int le = 0, np = p.length(), ns = s.length();
        for (int ri = 0; ri < ns; ri++)
        {
            mp[s[ri]]--;
            while (mp[s[ri]] < 0) // 如果有不是p里面的，--就很容易变成负数
            {
                mp[s[le]]++;
                le++;
            }
            if (ri - le + 1 == np)
                ans.push_back(le);
        }
        return ans;
    }
};