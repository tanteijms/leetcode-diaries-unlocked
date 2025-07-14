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