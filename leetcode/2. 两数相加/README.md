# [2. 两数相加](https://leetcode.cn/problems/add-two-numbers/)



## 题目

给你两个 **非空** 的链表，表示两个非负的整数。它们每位数字都是按照 **逆序** 的方式存储的，并且每个节点只能存储 **一位** 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

 

**示例 1：**

![img](./assets/addtwonumber1.jpg)

```
输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.
```

**示例 2：**

```
输入：l1 = [0], l2 = [0]
输出：[0]
```

**示例 3：**

```
输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
输出：[8,9,9,9,0,0,0,1]
```

 

**提示：**

- 每个链表中的节点数在范围 `[1, 100]` 内
- `0 <= Node.val <= 9`
- 题目数据保证列表表示的数字不含前导零



## 题解

- 时间复杂度: O(m+n)。只需遍历两个链表一次即可

- 空间复杂度: O(1)。仅用到若干额外遍历，最多new一个新的结点

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *cur1 = l1, *cur2 = l2, *pre = nullptr;
        int tag = 0; // 默认无进位
        // l1为答案链
        while (cur1 && cur2)
        {
            int sum = cur1->val + cur2->val + tag;
            tag = 0;
            if (sum >= 10)
            {
                tag = 1;
                sum %= 10;
            }
            cur1->val = sum;
            pre = cur1;
            cur1 = cur1->next;
            cur2 = cur2->next;
        }
        // 说明上面的循环是因为cur1走到空停止的
        // l1的长度≤l2
        if (!cur1)
        {
            pre->next = cur2;
            cur1 = cur2;
        }
        if (tag)
        {
            while (cur1)
            {
                int sum = cur1->val + tag;
                tag = 0;
                if (sum >= 10)
                {
                    tag = 1;
                    sum %= 10;
                }
                cur1->val = sum;
                pre = cur1;
                cur1 = cur1->next;
            }
        }
        if (tag)
        {
            ListNode *c = new ListNode(1);
            pre->next = c;
        }
        return l1;
    }
};
```





## points

1. 本题链表给的顺序就是从个位开始的，因此不用翻转

2. 整体思路同两数相加II

   直接进行遍历，记录一个进位标志tag，初始为0

   sum是cur1和cur2指向val的和，然后加上tag，记得要立刻把tag置零。对sum进行模10处理，如果有进位，则tag=1

   我们以l1为基准链表，把值更新进去，并且移动cur1和cur2

   注意此时还要记录一个pre，pre及以前的，都是已经加和完毕的节点

3. 下面退出循环，有两种可能，若l1过短，则把l2的后面的，接到l1后面。

4. 接着继续对后面的节点进行操作，方法和上述一样，但是sum加和少了一个val，只是当前节点和tag的和

5. 最后退出循环后，如果tag还为1，说明最后的进位超出了原来节点数的上限，需要new一个新的节点，当然值就是1

6. 最后return即可
