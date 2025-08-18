# [23. 合并 K 个升序链表](https://leetcode.cn/problems/merge-k-sorted-lists/)



## 题目

给你一个链表数组，每个链表都已经按升序排列。

请你将所有链表合并到一个升序链表中，返回合并后的链表。

 

**示例 1：**

```
输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6
```

**示例 2：**

```
输入：lists = []
输出：[]
```

**示例 3：**

```
输入：lists = [[]]
输出：[]
```

 

**提示：**

- `k == lists.length`
- $0 <= k <= 10^4$
- `0 <= lists[i].length <= 500`
- $-10^4 <= lists[i][j] <= 10^4$
- `lists[i]` 按 **升序** 排列
- `lists[i].length` 的总和不超过 $10^4$



## 题解

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        auto cmp = [](const ListNode *a, const ListNode *b)
        {
            return a->val > b->val;
        };
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq(cmp);
        for (auto head : lists)
        {
            if (head)
                pq.push(head); // 非空才push进堆里
        }
        ListNode dummy{};
        auto cur = &dummy;
        while (!pq.empty())
        {
            auto node = pq.top;
            pq.pop();
            if (node->next)
                pq.push(node->next);
            cur->next = node;
            cur = cur->next;
        }
        return dummy.next;
    }
};
```





## points

1. C++ priority_queue默认最大堆，把优先级高的元素放在堆顶

   自定义比较器，用lambda表达式。返回true表示第一个参数放在第二个参数后面，优先级更低，从而得到最小堆

   priority_queue是C++的优先队列，本质上就是heap

   三个参数 T 数据类型  Container 底层容器，用vector<T> 比较器的类型，可以自定义

   自己写的cmp传入pq的第三个参数，用decltype(cmp)

   decltypr是C++一个技巧，用来推到lambda表达式的类型

   前面写的auto cmp = [\](const ListNode* a, const ListNode* b) {

   ​	return ...

   };

   本质上cmp是一个变量，类型是lambda表达式的匿名类类型

   但这个类型没有名字

   因此用decltype把自定义的lambda类型拿出来，这里是类型

   这里并不直接使用cmp这个比较器，只是用他的类型。关于这个pq的比较方式，在pq(cmp)的时候指定

2. 本题思路为维护一个最小堆，每次pop堆顶的元素，然后加入到答案的链表数组里。并且把pop出的结点的next加入到最小堆里，自动维护排序

