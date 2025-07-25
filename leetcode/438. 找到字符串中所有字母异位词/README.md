# [438. 找到字符串中所有字母异位词](https://leetcode.cn/problems/find-all-anagrams-in-a-string/)



## 题目

给定两个字符串 `s` 和 `p`，找到 `s` 中所有 `p` 的 **异位词** 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

 

**示例 1:**

```
输入: s = "cbaebabacd", p = "abc"
输出: [0,6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
```

 **示例 2:**

```
输入: s = "abab", p = "ab"
输出: [0,1,2]
解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
```

 

**提示:**

- $1 <= s.length, p.length <= 3 * 10^4$
- `s` 和 `p` 仅包含小写字母



## 题解

### 解1

- 时间复杂度: O(n)。对于le和ri，都是在s这个字符串上进行遍历，没有回溯，因此就是s的字符串长

- 空间复杂度: O(26)。用到了map和mp两个哈希表，键是p当中的字符。

```cpp
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
```



### 解2

```cpp
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
```







## points

### 解1

1. 首先用一个map记录p所有的字母，另一个mp用来记录滑动窗口过程中，符合在p中的字母。当map==mp时，说明二者用到的字母是完全一样的，因此就是异构的。
2. 记录le和ri，其内部就是在整个s上滑动的窗口
3. 主循环：不断向右遍历ri。如果ri当前指向的字母在p里，就进入判断逻辑，给mp记录的当前字母++。并且需要将le右移，判断条件是如果当前le指的字符不在p里，就右移，这样能够确保le到ri这个区间上都是p里的字符
4. 有一种情况是le当前指的是p里的，ri指的也是。但是中间可能有不是p里的字符。这样可能导致死循环，因为le只在加入到ans以后才右移。根据这种情况，在每次向右移动ri之后进行判断，如果当前le到ri这个区间组成的字串，长度已经大于p的长度，那么就将le进行右移，直到长度恰好等于p的长度
5. 当le到ri符合题意的时候，进行map和mp的判断，如果二者完全一样，说明le到ri的字串就是p的一个异构（因为使用的字符完全一样，只是顺序不同），将le的索引添加到ans后，并且mp中，le当前指向的字符--，然后右移le
6. ri遍历到的每一个字符，在ri++以后对le到ri的长度进行判断，在右移le的时候，注意当前le指向的字符是否在p里。这个可以用mp.count()去判断，如果在mp里，就给mp中对应le指的字符--，然后右移le



### 解2

1. 只需要记录一个mp即可。先遍历一遍p，mp存储p中所有字符存储的个数

2. 在主循环里，ri每次右移，遇到新的字符就给mp中ri当前指的字符--

   然后进行判断，如果此时mp对应的ri指的字符，变成了负数，那么要么是当前字符不是p当中的，从0减成了负的；要么当前le到ri区间上的这个子串，都是p的字符，但是数量多了。因此需要调整左窗口

3. 给le当前指的字符在mp当中的值++，然后右移le，删除掉此字符

4. 移动完le后，也有可能因为ri当前的字符不在p内，导致直接完全删除，le到了ri的右边。这时再判断一下le到ri区间字串的长度，如果等于p.length()，说明对了，ri当前字符在p内，该字串满足题意

   给ans后面加上le的值