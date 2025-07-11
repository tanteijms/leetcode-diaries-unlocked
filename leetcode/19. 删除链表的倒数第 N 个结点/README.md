# [19. 删除链表的倒数第 N 个结点](https://leetcode.cn/problems/remove-nth-node-from-end-of-list/)



## 题目

给你一个链表，删除链表的倒数第 `n` 个结点，并且返回链表的头结点。

 

**示例 1：**

![img](./assets/remove_ex1.jpg)

```
输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
```

**示例 2：**

```
输入：head = [1], n = 1
输出：[]
```

**示例 3：**

```
输入：head = [1,2], n = 1
输出：[1]
```

 

**提示：**

- 链表中结点的数目为 `sz`
- `1 <= sz <= 30`
- `0 <= Node.val <= 100`
- `1 <= n <= sz`

 

**进阶：**你能尝试使用一趟扫描实现吗？



## 题解

- 时间复杂度：O(length)
- 空间复杂度：O(1)

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // 由于可能删除头结点，因此需要创建dummy
        ListNode dummy(0, head);
        ListNode *right = &dummy, *left = &dummy;
        for (int i = 0; i < n; i++)
            right = right->next;

        while (right->next)
        {
            right = right->next;
            left = left->next;
        }
        // 当right->next味nullptr，此时right就恰好是最后一个结点，而left与right差n个。
        // 因此left就恰好是要删除节点的前一个结点
        // 很巧妙的定位方法
        ListNode *temp = left->next;
        left->next = temp->next;
        delete temp;
        return dummy.next; // 这里不要return head，因为有可能删除的就是头结点，这样被释放掉了
        // 而dummy可以始终保持是head之前，因为如果删head的话，dummy结点就会更新
    }
};
```





## points

1. dummy：删除头结点的时候，需要
2. 如何更快的找到该 倒数n+1个，一趟扫描