class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.size() < t.size())
            return "";

        int cnt[128] = {0}; // ASCII 128个字符
        for (char c : t)
            cnt[c]++;

        int num = t.size(), le = 0, minLen = INT_MAX, start = 0;
        unordered_set<char> t_set(t.begin(), t.end());

        for (int ri = 0; ri < s.size(); ri++)
        {
            if (t_set.count(s[ri]))
            {
                if (cnt[s[ri]] > 0)
                    num--;
                cnt[s[ri]]--;
            }

            while (num == 0) // 满足条件，尝试缩小窗口
            {
                if (ri - le + 1 < minLen)
                {
                    minLen = ri - le + 1;
                    start = le;
                }

                if (t_set.count(s[le]))
                {
                    cnt[s[le]]++;
                    if (cnt[s[le]] > 0)
                        num++;
                }
                le++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};