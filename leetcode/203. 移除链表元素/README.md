# [203. 移除链表元素](https://leetcode.cn/problems/remove-linked-list-elements/)



## 题目

给你一个链表的头节点 `head` 和一个整数 `val` ，请你删除链表中所有满足 `Node.val == val` 的节点，并返回 **新的头节点** 。

 

**示例 1：**

![img](./assets/removelinked-list.jpg)

```
输入：head = [1,2,6,3,4,5,6], val = 6
输出：[1,2,3,4,5]
```

**示例 2：**

```
输入：head = [], val = 1
输出：[]
```

**示例 3：**

```
输入：head = [7,7,7,7], val = 7
输出：[]
```

 

**提示：**

- 列表中的节点数目在范围 `[0, 104]` 内
- `1 <= Node.val <= 50`
- `0 <= val <= 50`



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
    ListNode *removeElements(ListNode *head, int val)
    {
        // 因为可能删除掉head，所以要dummy
        ListNode dummy(0, head);
        ListNode *cur = &dummy;
        while (cur->next) // 遍历整个。因为cur是前一个其实，所以注意条件要判断cur->next
        {
            if (cur->next->val == val)
            {
                ListNode *nxt = cur->next;
                cur->next = nxt->next;
                delete nxt;
            }
            else
                cur = cur->next;
        }
        return dummy.next;
    }
};
```





## points

1. while的循环条件应该是cur->next，因为每次都会取它的值，需要判断非空