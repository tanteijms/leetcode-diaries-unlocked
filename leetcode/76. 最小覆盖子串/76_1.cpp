class Solution
{
public:
    string minWindow(string s, string t)
    {
        if (s.size() < t.size())
            return "";
        string initial_ans = s + "NULL";
        string ans = initial_ans; // 因为求最小子串，所以一开始令ans=最长的s拼接一个"NULL",因为有可能s==t，这样会导致错误
        int cnt['z']{}, num = 0;  // 全由字母组成，则造一个'Z'大小的数组，用来存储当前信息，t串是否含有某字符
        for (char c : t)
        {
            if (cnt[c] == 0) // 排除可能记录t中有的重复的字符
            {
                cnt[c]++;
                num++; // 记录t中不重复的字符出现的次数
            }
        }
        int t_len = num; // 这个t_len实际上是假的，因为进行了去重
        int len = s.size(), le = 0;
        for (int ri = 0; ri < len; ri++) // 滑动窗口遍历整个s字符串
        {
            if (find(t.begin(), t.end(), s[ri]) != t.end()) // 右指针找到的新的这个字符，在s中出现了
            {
                if (cnt[s[ri]] == 1) // 该字符是s中新出现的字符
                {
                    cnt[s[ri]]--;
                    num--; // 认为num==0时，满足所有字符都恰好有一个。如果某字符出现多次，用别的方式去记录。
                }

                else // 子串内已经有了该字符，一定是<=0的
                    cnt[s[ri]]--;
            }

            if (ri - le + 1 >= t_len && num == 0) // 确保至少要都有这些字符，才能满足题意。否则跳过
            {
                while (num == 0) // 直到我删除了第一个有用的字符
                {
                    // 更新ans放在最前面，因为每次都是满足题意的。当我把le指向的字符删除掉以后，可能导致不满足题意
                    if (ans.size() > ri - le + 1)        // 如果当前更短，则更新
                        ans = s.substr(le, ri - le + 1); // nums==0确保一定有所有的字符，则每一次都是满足条件的，可以尝试更新

                    if (find(t.begin(), t.end(), s[le]) != t.end()) // 当前le指向的字符在t里面
                    {
                        if (cnt[s[le]] == 0) // 如果当前字符记录为0，说明只出现了一次
                        {
                            cnt[s[le]]++; // 复原
                            num++;
                        }

                        else              // 这里，cnt[s[le]]一定<=-1，因为num==0保证了每个字符都出现，但出现几次，是通过继续减小cnt[c]的值来体现的
                            cnt[s[le]]++; // 只需给他的记录值++即可，不用回复num。因为是重复出现的
                    }
                    le++; // 左指针右移
                }
            }
        }

        return ans == initial_ans ? "" : ans;
    }
};