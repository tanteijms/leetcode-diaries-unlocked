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
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode dummy(0, head); // 临时的栈变量
        ListNode *p0 = &dummy;
        ListNode *cur = head, *pre = nullptr;
        int length = 0;
        while (cur)
        {
            length++;
            cur = cur->next;
        }
        for (; length - k >= 0; length -= k) // 每次判断当前剩余节点是否还够k个，如果够，则在当次循环结束后，从length中减去k
        {
            ListNode *p0nxt = p0->next;
            cur = p0nxt;
            for (int i = 0; i < k; i++)
            {
                ListNode *nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
            }
            p0nxt->next = cur;
            p0->next = pre;
            p0 = p0nxt;
        }
        return dummy.next;
    }
};