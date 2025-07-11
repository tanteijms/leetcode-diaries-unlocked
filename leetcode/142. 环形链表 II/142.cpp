/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        int tag = 0;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
            {
                tag = 1;
                break;
            }
        }
        if (tag == 0)
            return nullptr;
        
        while(head!=slow)
        {
            slow=slow->next;
            head=head->next;
        }
    }
};