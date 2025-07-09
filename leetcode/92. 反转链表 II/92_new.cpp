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
        ListNode dummy(0, head);
        ListNode *p0 = &dummy;
        // 下面通过不断p0=p0->next来把p0定位到开始的前一个
        int cnt = left;
        while (--cnt)
            p0 = p0->next;

        // 这样自然而然，p0的next就是left
        ListNode *cur = p0->next, *pre = nullptr;
        cnt = right - left + 1;
        while (cnt--)
        {
            ListNode *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        // 由于循环了right-left+1次，最后出循环的时候，cur已经到了right+1，pre在right
        p0->next->next = cur;
        p0->next = pre;
        // 即使right就是原链表的最后一个，那刚好直接cur=nullptr
        return dummy.next;
    }
};