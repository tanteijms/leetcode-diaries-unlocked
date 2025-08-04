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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode dummy(0);
        ListNode *pre = &dummy, *cur1 = list1, *cur2 = list2;

        // cur1和cur2是遍历过程中新的要接入的结点，分别在list和list2里
        // pre及以前是已经排序好的
        while (cur1 && cur2)
        {
            if (cur1->val >= cur2->val)
            {
                pre->next = cur2;
                cur2 = cur2->next;
            }
            else
            {
                pre->next = cur1;
                cur1 = cur1->next;
            }
            pre = pre->next;
        }

        pre->next = cur1 ? cur1 : cur2;
        return dummy.next;
    }
};