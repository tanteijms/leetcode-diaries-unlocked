# [208. 实现 Trie (前缀树)](https://leetcode.cn/problems/implement-trie-prefix-tree/)



## 题目

**[Trie](https://baike.baidu.com/item/字典树/9825209?fr=aladdin)**（发音类似 "try"）或者说 **前缀树** 是一种树形数据结构，用于高效地存储和检索字符串数据集中的键。这一数据结构有相当多的应用情景，例如自动补全和拼写检查。

请你实现 Trie 类：

- `Trie()` 初始化前缀树对象。
- `void insert(String word)` 向前缀树中插入字符串 `word` 。
- `boolean search(String word)` 如果字符串 `word` 在前缀树中，返回 `true`（即，在检索之前已经插入）；否则，返回 `false` 。
- `boolean startsWith(String prefix)` 如果之前已经插入的字符串 `word` 的前缀之一为 `prefix` ，返回 `true` ；否则，返回 `false` 。

 

**示例：**

```
输入
["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
[[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
输出
[null, null, true, false, true, null, true]

解释
Trie trie = new Trie();
trie.insert("apple");
trie.search("apple");   // 返回 True
trie.search("app");     // 返回 False
trie.startsWith("app"); // 返回 True
trie.insert("app");
trie.search("app");     // 返回 True
```

 

**提示：**

- `1 <= word.length, prefix.length <= 2000`
- `word` 和 `prefix` 仅由小写英文字母组成
- `insert`、`search` 和 `startsWith` 调用次数 **总计** 不超过 $3 * 10^4$ 次



## points

1. trie 树存储字符的时候，并不需要显式地为每一个节点都存一个 char 类型的 val，而是直接用当前节点在上一级节点的指针，它是存在哪里的，也就是 0-25 号元素的哪一个，直接用数组的序号来表示即可

2. 首先自己定义节点类型。由于 26 个字母我们按照顺序直接用指针数组表示即可，因此不需要 val 节点。要有一个 Node*的数组，26 个元素。一个 bool 类型的 end 表示到当前节点，是否为单词的末尾

3. 进入Trie类的定义

   首先对于每一个前缀树，都要有一个根节点。在Java里会将它定义为final的，的确，因为我们并不需要修改这个根节点，只需要修改它里面的值，来表示不同的字母开头即可

   定义工具函数，find。对于传入的一个string，用来在前缀树里进行查找。从root开始，遍历string里的每一个字符，然后通过计算-'a'来得出它对应的数组下标。若对于任意一个字符，在当前节点的子数组里找不到，立即返回0，匹配失败。只有遍历完所有的字符，才成功。这时根据当前节点end来判断是前缀还是整个单词本身

   定义工具函数，destroy，递归调用来删除所有的节点。终止条件是访问到了空节点，不用删除。否则，就遍历所有的子数组的节点并递归调用删除。最后删除本节点。本质上是一个后序遍历

   下面是public对外的接口。

   析构函数，~Trie()。直接对root调用destroy即可

   定义insert从根节点开始。对于string的每一个字符，判断当前节点的子数组里是否包含，如果是，就继续，如果没有，就自己创建一个新的节点出来。遍历完整个单词以后，设置end为true。

   search和startWith可以直接用find函数，然后根据返回值来返回。但注意一个单词本身也是自己的前缀，因此只要find找到了，是否为前缀就返回true

   