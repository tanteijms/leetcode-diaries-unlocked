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