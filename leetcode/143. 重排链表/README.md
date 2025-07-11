# [143. 重排链表](https://leetcode.cn/problems/reorder-list/)



## 题目

给定一个单链表 `L` 的头节点 `head` ，单链表 `L` 表示为：

```
L0 → L1 → … → Ln - 1 → Ln
```

请将其重新排列后变为：

```
L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
```

不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

 

**示例 1：**

![img](./assets/1626420311-PkUiGI-image.png)

```
输入：head = [1,2,3,4]
输出：[1,4,2,3]
```

**示例 2：**

![img](./assets/1626420320-YUiulT-image.png)

```
输入：head = [1,2,3,4,5]
输出：[1,5,2,4,3]
```

 

**提示：**

- 链表的长度范围为 `[1, 5 * 104]`
- `1 <= node.val <= 1000`



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
    void reorderList(ListNode *head)
    {
        ListNode *slow = head, *fast = head, *pre = nullptr;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            pre = slow; // pre和slow是一组pre和cur
            slow = slow->next;
        }
        // 退出循环时，slow恰好就是【中间结点】
        // 要把slow前一个结点记录下来，并拆分两段
        if (pre)                 // 防止比如说，只有一个结点，那pre是nullptr
            pre->next = nullptr; // 这是slow的前一个，要断开
        // 然后以slow为新的head，对后续的进行反转
        ListNode *cur = slow;
        pre = nullptr; // 此时pre和cur绑定了，把pre初始化掉
        while (cur)
        {
            ListNode *nxt = cur->next;
            cur->next = pre; // 第一次循环：slow的next改为nullptr
            pre = cur;
            cur = nxt;
        }
        // 反转后，pre就是新的head
        ListNode *head2 = pre;
        // 下面对两段进行归并
        // 由于第二段长度≥第一段，则以第一段为循环判断
        cur = head;
        while (cur)
        {
            // 如果是奇数，cur会比head2更早一步到达nullptr
            ListNode *nxt1 = cur->next, *nxt2 = head2->next;
            cur->next = head2;
            head2->next = nxt1;
            pre = head2;
            cur = nxt1;
            head2 = nxt2;
        }
        // 如果一样长，head2会和cur一起变成nullptr
        // 当退出时，head2有可能还在最后一个结点。
        // 目前slow这个中间结点没串上。这是因为在退出循环后，没有处理
        if (head2)
            pre->next = head2;
    }
};
```





## points

1. 结合【链表的中间节点】与【反转链表】，因为本题要实现的效果是：1 2 3 4 5  变为 1 5 2 4 3，可以看到，1 2是正序的，5 4 3是逆序的，因此可以考虑反转。

   为什么把3算到5 4 3，而不是1 2 3里呢。因为考虑如果是偶数个结点：1 2 3 4，变为1 4 2 3，则可以看到，是1 2和4 3两组。

   结合奇偶两个来看，恰好和【链表的中间节点】这题是一样的。因此把中间节点（奇）或中间的右边结点（偶）归到后半段并反转，是更合适的。

   且可以清晰地看到，找到的这个中间节点，恰好就是新链表的尾

2. 当分组、并反转以后，可以进行归并，由于是1 2   5 4 3，每次串起来两边的一个，所以就是最基本的归并操作了

   注意每次要保留cur->next，来确保后续的移动是正确的

3. 因为我在找中间结点之后，手动把前后两部分的链表切断掉了，所以在后面归并的循环里，比如1 2 3 4 5，变成1 2    5 4 3。当cur为2，head2为4时，head2的next会被赋为cur的next，也就是nullptr。假设我当时没有断开的话，退出循环后就会自动和3连起来了，因此不会导致奇数的时候少一个结点。

   不过还好，手动不上就可以了

4. 注意在手动断开的时候，pre不一定有值，因此要先判断，再处理他的next