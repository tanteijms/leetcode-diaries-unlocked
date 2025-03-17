int lengthOfLongestSubstring(char *s)
{
    int hash[256] = {0}; // 扩展ASCII表256个

    int ans = 0, le = 0;
    for (int ri = 0; s[ri] != '\0'; ri++)
    {
        char c = s[ri];
        hash[(unsigned char)c]++;

        while (hash[(unsigned char)c] > 1)
        {
            hash[(unsigned char)s[le]]--;
            le++;
        }

        ans = ans < ri - le + 1 ? ri - le + 1 : ans;
    }

    return ans;
}