# [876. 链表的中间结点](https://leetcode.cn/problems/middle-of-the-linked-list/)

[代码1.cpp](876.cpp)  
[代码2.cpp](876_2.cpp)  

## 题目

给你单链表的头结点 `head` ，请你找出并返回链表的中间结点。

如果有两个中间结点，则返回第二个中间结点。

 

**示例 1：**

![img](./assets/lc-midlist1.jpg)

```
输入：head = [1,2,3,4,5]
输出：[3,4,5]
解释：链表只有一个中间结点，值为 3 。
```

**示例 2：**

![img](./assets/lc-midlist2.jpg)

```
输入：head = [1,2,3,4,5,6]
输出：[4,5,6]
解释：该链表有两个中间结点，值分别为 3 和 4 ，返回第二个结点。
```

 

**提示：**

- 链表的结点数范围是 `[1, 100]`
- `1 <= Node.val <= 100`



## 题解

- 时间复杂度：O(n)
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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) // 考虑如何停止循环。
        // 奇数：fast恰好在最后一个结点的时候，结束。此时特征为fast->next==nullptr
        // 偶数：fast在fast->next的时候，结束。此时fast自身就是nullptr
        {
            // 把判断移到while里面去
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};
```





## points

1. 快慢指针，一个走2，一个走1

2. 长度奇数，若快在末尾，则慢一定在中间

   长度偶数，若快在空，则慢一定在中间靠右的那个（符合题目要求）

3. 注：每次在移动之前就进行判断：

   slow不需要管他的取值范围，不会是null

   而fast，如果是奇数，目前恰好在最后一个，那么访问fast->next->next就是非法的，因为此时fast->next已经是nullptr。

   如果是偶数，目前恰好在倒数第二个，正常访问。fast和slow都分别移动最后一次

   而再下一次循环，fast自身已经是nullptr了，停止循环

   因此可知：移动之前进行的判断，可以移动到while的判断条件里面去。根据总结，每次判断fast->next和fast是不是nullptr即可