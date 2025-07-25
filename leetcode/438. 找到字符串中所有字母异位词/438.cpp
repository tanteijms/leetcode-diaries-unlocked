class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        vector<int> ans;
        unordered_map<char, int> map; // 存p，是模板
        unordered_map<char, int> mp;  // 存每一个字串，用来对比
        for (char c : p)
            map[c]++;
        int ns = s.length(), np = p.length();
        int le = 0, ri = 0;
        while (le <= ri && ri < ns)
        {
            if (map.count(s[ri])) // ri当前所指是p的一个字符
            {
                mp[s[ri]]++;
                while (!map.count(s[le]))
                    le++;
                // 这时确保了le到ri都是p里面的字符，且都记录在mp里了
                if (map == mp) // 如果所有字符都及数量都相等
                {
                    ans.push_back(le);
                    mp[s[le]]--; // le走了，删掉出此范围的字符
                    le++;
                }
            }
            ri++;
            while (ri - le + 1 > np)
            {
                if (mp.count(s[le]))
                    mp[s[le]]--; // le走了，删掉出此范围的字符
                le++;
            }
        }
        return ans;
    }
};