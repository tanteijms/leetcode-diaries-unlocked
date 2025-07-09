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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *pre = nullptr;
        ListNode *cur = head;
        ListNode *p0 = new ListNode(), *nxt = nullptr;
        int cnt = left;
        while (--cnt) // 如果cnt=left=1就不用移动，这样直接跳出循环。
        {
            nxt = cur->next;
            pre = cur;
            cur = nxt;
        }
        // 先找到p0
        if (cur == head)
            p0->next = head;
        else
            p0 = pre;
        // now，pre是p0，cur是第一个需要反转的。开始操作中间的部分
        // 把中间的部分就当作是一个单独的整体反转的链表，只是头尾需要单独处理
        cnt = right - left;
        while (cnt--)
        {
            nxt = cur->next;
            cur->next = pre; // 在cur为left的时候会先赋为pre
            pre = cur;
            cur = nxt;
        }
        // 出循环时，pre在right-1，cur在right
        nxt = cur->next;
        cur->next = pre;
        if (p0->next == head) // 从原来的第一个开始反转
        {
            head = cur;
            p0->next->next = nxt;
        }
        else
        {
            p0->next->next = nxt;
            p0->next = cur;
        }
        // 如果right恰好等于最后呢。已满足
        return head;
    }
};