class Solution
{
public:
    int longestSemiRepetitiveSubstring(string s)
    {
        int ans = 2, le = 0, tag = 0; // tag标志当前遍历到的子串是否满足要求
        int n = s.size();             // size含前后两""
        if (n < 3)
            return n;
        for (int ri = 1; ri < n; ri++)
        {
            char x = s[ri];

            if (x == s[ri - 1])
                tag++;

            while (tag > 1)
            {
                if (s[le] == s[le + 1])
                    tag--;

                le++;
            }

            ans = std::max(ans, ri - le + 1);
        }

        return ans;
    }
};