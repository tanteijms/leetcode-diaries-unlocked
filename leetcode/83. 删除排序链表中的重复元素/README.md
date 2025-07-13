# [83. 删除排序链表中的重复元素](https://leetcode.cn/problems/remove-duplicates-from-sorted-list/)



## 题目

给定一个已排序的链表的头 `head` ， *删除所有重复的元素，使每个元素只出现一次* 。返回 *已排序的链表* 。

 

**示例 1：**

![img](./assets/list1.jpg)

```
输入：head = [1,1,2]
输出：[1,2]
```

**示例 2：**

![img](./assets/list2.jpg)

```
输入：head = [1,1,2,3,3]
输出：[1,2,3]
```

 

**提示：**

- 链表中节点数目在范围 `[0, 300]` 内
- `-100 <= Node.val <= 100`
- 题目数据保证链表已经按升序 **排列**



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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *cur = head;
        while (cur && cur->next)
        {
            ListNode *nxt = cur->next;
            if (cur->val == nxt->val)
            {
                cur->next = cur->next->next;
                delete nxt;
            }
            else
                cur = nxt;
        }
        return head;
    }
};
```





##  points

1. 删除的时候，如果头结点的值有重复的，那删掉后面的就可以，保留头结点。因为不涉及对头结点的处理，因此不需要dummy
2. 由于链表结点数[0, 300]，因此长度可能为0，本解法在while判断cur（初值为head）时，包含了这个的判断，会跳出循环，直接返回head
3. 在while的判断条件中，只要判断cur->next就可以，因为涉及到的是对cur->next的操作，要取它的next。如果每次都判断cur和cur->next的话，会有一点麻烦。不过这样，可以很好的规避链表为空的情况，不用单独写判断