# [2487. 从链表中移除节点](https://leetcode.cn/problems/remove-nodes-from-linked-list/)



## 题目

给你一个链表的头节点 `head` 。

移除每个右侧有一个更大数值的节点。

返回修改后链表的头节点 `head` 。

 

**示例 1：**

![img](./assets/drawio.png)

```
输入：head = [5,2,13,3,8]
输出：[13,8]
解释：需要移除的节点是 5 ，2 和 3 。
- 节点 13 在节点 5 右侧。
- 节点 13 在节点 2 右侧。
- 节点 8 在节点 3 右侧。
```

**示例 2：**

```
输入：head = [1,1,1,1]
输出：[1,1,1,1]
解释：每个节点的值都是 1 ，所以没有需要移除的节点。
```

 

**提示：**

- 给定列表中的节点数目在范围 $[1, 10^5]$ 内

  $1 <= Node.val <= 10^5$



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
    ListNode *reverseLinkList(ListNode *head)
    {
        ListNode *cur = head, *pre = nullptr;
        while (cur)
        {
            ListNode *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }

public:
    ListNode *removeNodes(ListNode *head)
    {
        // 反转之后可以正着想，且删除的顺序也是反转后的正序，不会回溯
        head = reverseLinkList(head);
        ListNode *cur = head;
        while (cur->next) // 每次对cur，判断，只要后面的小，就删掉后面的，直到比自己大。
        // 这样保证了在cur不动的情况下，一直删掉后面所有满足的情况
        {
            if (cur->val > cur->next->val)
                cur->next = cur->next->next; // 不回收了
            else
                cur = cur->next;
        }
        return reverseLinkList(head);
    }
};
```





## points

1. 由于删掉后面的以后，可能导致前面的结点也需要删除，因此导致回溯

   递归思想是ok的。而要想避免递归，考虑先反转，因为反转之后，删除的顺序就变得正常了

2. 注意写reverse函数之后，要把head更新为它的返回值

