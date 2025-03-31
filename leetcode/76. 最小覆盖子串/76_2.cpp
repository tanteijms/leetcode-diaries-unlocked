class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.size() < t.size())
            return "";
        int minLen = INT_MAX;
        int cnt[123]{}; // 全由字母组成，则造一个'Z'大小的数组，用来存储当前信息，t串是否含有某字符
        for (char c : t)
            cnt[c]++;
        int num = t.size(); // t中所有字符。用num来检测是否至少包含t中所有字符（重复性用cnt的负值去考虑）
        int len = s.size(), le = 0, start = 0;
        for (int ri = 0; ri < len; ri++) // 滑动窗口遍历整个s字符串
        {
            if (find(t.begin(), t.end(), s[ri]) != t.end()) // 右指针找到t含有的字符
            {
                if (cnt[s[ri]] > 0)
                    num--;
                cnt[s[ri]]--;
            }

            if (ri - le + 1 >= t.size() && num == 0) // 确保至少要都有这些字符，才能满足题意。否则跳过
            {
                while (num == 0) // 直到我删除了第一个有用的字符
                {
                    // 更新ans放在最前面，因为每次都是满足题意的。当我把le指向的字符删除掉以后，可能导致不满足题意
                    if (minLen > ri - le + 1) // 如果当前更短，则更新
                    {
                        start = le; // 每一次都是满足条件的，可以尝试更新
                        minLen = ri - le + 1;
                    }

                    if (find(t.begin(), t.end(), s[le]) != t.end()) // 当前le指向的字符在t里面
                    {
                        if (cnt[s[le]] >= 0)
                            num++;
                        cnt[s[le]]++; // 复原
                    }
                    le++; // 左指针右移
                }
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};