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
        ListNode *cur1 = l1, *pre1 = nullptr, *cur2 = l2, *pre2 = nullptr;
        int cnt1 = 0, cnt2 = 0;

        // 进行两个链表的反转
        while (cur1)
        {
            cnt1++;
            ListNode *nxt = cur1->next;
            cur1->next = pre1;
            pre1 = cur1;
            cur1 = nxt;
        }
        l1 = pre1;

        while (cur2)
        {
            cnt2++;
            ListNode *nxt = cur2->next;
            cur2->next = pre2;
            pre2 = cur2;
            cur2 = nxt;
        }
        l2 = pre2;

        // 这里我以长的为基准，把短的值加到长的上去。认为cur1是长的，cur2是短的
        // 要直接交换的是l1 和 l2，也就是关于原本两个链表的属性，彻底交换过来（head 和 length）
        if (cnt1 < cnt2)
        {
            ListNode *tem = l1;
            l1 = l2;
            l2 = tem;

            int temp = cnt1;
            cnt1 = cnt2;
            cnt2 = temp;
        }

        cur1 = l1, cur2 = l2; // 重新赋值。不论是否交换了两链表，都重新进行初始化，开始从反转后的头往前走，进行加法

        // 链表已反转。开始从后往前做加法
        int tag = 0;                   // 设置进位标志
        for (int i = 0; i < cnt2; i++) // 循环：短的数的位数 次。退出后单独处理l1剩余的进位问题
        {
            cur1->val += cur2->val + tag;
            tag = 0; // 用完进位标志以后就直接清零
            if (cur1->val >= 10)
            {
                tag = 1;
                cur1->val %= 10;
            }
            ListNode *nxt = cur1->next;
            pre1 = cur1;
            cur1 = nxt;
            nxt = cur2->next;
            pre2 = cur2;
            cur2 = nxt;
        }

        for (int i = cnt2; i < cnt1; i++)
        {
            cur1->val += tag;
            tag = 0;
            if (cur1->val >= 10)
            {
                tag = 1;
                cur1->val %= 10;
            }
            if (tag == 0)
                break;
            ListNode *nxt = cur1->next;
            pre1 = cur1;
            cur1 = nxt;
        }

        // 还要处理如果最终位数多了一位
        if (tag == 1)
            pre1->next = new ListNode(1); // next自动为nullptr

        cur1 = l1;
        pre1 = nullptr;
        while (cur1)
        {
            ListNode *nxt = cur1->next;
            cur1->next = pre1;
            pre1 = cur1;
            cur1 = nxt;
        }
        return pre1;
    }
};