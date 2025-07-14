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