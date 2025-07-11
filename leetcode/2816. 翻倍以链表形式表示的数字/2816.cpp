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
    ListNode *doubleIt(ListNode *head)
    {
        ListNode *cur = head, *pre = nullptr;
        int cnt = 0;
        while (cur)
        {
            cnt++;
            ListNode *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }

        head = pre;
        cur = head;
        pre = nullptr;
        int tag = 0;
        for (int i = 0; i < cnt; i++) // 遍历每一个结点
        {
            cur->val = cur->val * 2 + tag;
            tag = 0;
            if (cur->val >= 10)
            {
                tag = 1;
                cur->val %= 10;
            }
            ListNode *nxt = cur->next; // 记得要移动指针
            pre = cur;                 // 但是不用反转！
            cur = nxt;
        }
        if (tag == 1)                    // pre是当前的末尾
            pre->next = new ListNode(1); // 此处pre为nullptr了

        // 反转回来
        cur = head;
        pre = nullptr;
        while (cur)
        {
            ListNode *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
};