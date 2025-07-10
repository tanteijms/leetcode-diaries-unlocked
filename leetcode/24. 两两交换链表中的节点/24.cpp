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
    ListNode *swapPairs(ListNode *head)
    {
        // 总节点数[0, 100]，但没说奇偶
        ListNode dummy(0, head);
        ListNode *p0 = &dummy;

        // 遍历整个链表，取总结点数
        int cnt = 0;
        ListNode *cur = head, *pre = nullptr;
        while (cur)
        {
            cnt++;
            cur = cur->next;
        }

        for (; cnt - 2 >= 0; cnt -= 2)
        {
            ListNode *p0nxt = p0->next; // p0恰好是要进行调换的前置结点
            cur = p0nxt;
            for (int i = 0; i < 2; i++) // 执行2次
            {
                ListNode *nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
            }
            // 每次交换完之后需要更新p0
            p0nxt->next = cur;
            p0->next = pre;
            p0 = p0nxt; // p0时刻更新为要调整的前一个
        }
        return dummy.next;
    }
};