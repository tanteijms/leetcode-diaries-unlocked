# [49. 字母异位词分组](https://leetcode.cn/problems/group-anagrams/)



## 题目

给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

 

**示例 1:**

**输入:** strs = ["eat", "tea", "tan", "ate", "nat", "bat"]

**输出:** [["bat"],["nat","tan"],["ate","eat","tea"]]

**解释：**

- 在 strs 中没有字符串可以通过重新排列来形成 `"bat"`。
- 字符串 `"nat"` 和 `"tan"` 是字母异位词，因为它们可以重新排列以形成彼此。
- 字符串 `"ate"` ，`"eat"` 和 `"tea"` 是字母异位词，因为它们可以重新排列以形成彼此。

**示例 2:**

**输入:** strs = [""]

**输出:** [[""]]

**示例 3:**

**输入:** strs = ["a"]

**输出:** [["a"]]

 

**提示：**

- $1 <= strs.length <= 10^4$
- `0 <= strs[i].length <= 100`
- `strs[i]` 仅包含小写字母



## 题解

- 时间复杂度：$O(n * 100*log_2 100)$。第一次遍历strs O(n)，每一趟都对取到的string sort，最坏$O(100*log_2 100)$(字符串最长100)。之后遍历哈希表，最坏O(n)：因为相当于是对所有元素分组了，虽然嵌套两层循环，但实际上遍历的就是所有的元素，n个
- 空间复杂度：O(n)。哈希表存储。

```cpp
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
```



## points

1. 第一次遍历，对于取到的每一个string，用字典序存入哈希表里。用sort()方法将取到的每一个string，排序后存入新的变量，然后作为哈希表的键
2. 哈希表的值维护的是所有排序后等于键字符串的，在strs里的索引值，是一个int vector
3. 之后遍历哈希表，这时不关心它的键了，因为是排序后的，不具有原数组的字符串顺序。我们关心哈希表的值，对于每一个值，都是一个int vector，这样对应原数组strs的一些元素。遍历这个存放索引的vector，从strs里把这些索引对应的字符串拿出来，放入一个vector<string>里。若当前哈希表的键值对已结束，就把刚才的temp再加入到ans里。遍历结束后返回ans