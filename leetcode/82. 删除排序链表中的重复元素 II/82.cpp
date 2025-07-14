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
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode dummy(0, head);
        ListNode *cur = &dummy;
        while (cur->next && cur->next->next) // 因为cur是要删除的前一个结点
        // 每次都来处理的是它下一个，以及下下一个
        // 如果总结点数为0，则cur是dummy，不会错误
        {
            int val = cur->next->val; // 记录这个可能重复的val，否则后面删除以后，没办法与新的值进行比对
            // 因此要取它next的val
            if (cur->next->next->val == val)
            {
                while (cur->next && cur->next->val == val)
                {
                    ListNode *pre = cur->next;
                    cur->next = cur->next->next; // 修改cur，来删掉cur的下一个
                    delete pre;                  // 目前没删掉第一个重复的，只是删掉了后面的多余的
                }
            }
            else // 不相等，则往下一个走
                cur = cur->next;
        }
        return dummy.next; // 因为有可能头结点被删掉了
    }
};