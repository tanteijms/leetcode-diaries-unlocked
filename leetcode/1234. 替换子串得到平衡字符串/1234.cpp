class Solution
{
public:
    int balancedString(string s)
    {
        int len = s.length(), m = len / 4, cnt['Z']{};

        for (char c : s)
            cnt[c]++;

        if (cnt['Q'] == m && cnt['W'] == m && cnt['E'] == m && cnt['R'] == m)
            return 0;

        int ans = len, le = 0;

        for (int ri = 0; ri < len; ri++)
        {
            cnt[s[ri]]--;
            while (cnt['Q'] <= m && cnt['W'] <= m && cnt['E'] <= m && cnt['R'] <= m)
            {
                ans = min(ans, ri - le + 1);
                ++cnt[s[le++]];
            }
        }

        return ans;
    }
};
/*
 * 部分代码改编自 @EndlessCheng 的开源仓库：
 * https://github.com/EndlessCheng/codeforces-go/blob/master/leetcode/
 * 该仓库采用 MIT 许可证开源。
 *
 * 原始 MIT 许可证：
 *
 * MIT License
 *
 * Copyright (c) 2019 Σndless
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */