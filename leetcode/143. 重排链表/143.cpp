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
    void reorderList(ListNode *head)
    {
        ListNode *slow = head, *fast = head, *pre = nullptr;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            pre = slow; // pre和slow是一组pre和cur
            slow = slow->next;
        }
        // 退出循环时，slow恰好就是【中间结点】
        // 要把slow前一个结点记录下来，并拆分两段
        if (pre)                 // 防止比如说，只有一个结点，那pre是nullptr
            pre->next = nullptr; // 这是slow的前一个，要断开
        // 然后以slow为新的head，对后续的进行反转
        ListNode *cur = slow;
        pre = nullptr; // 此时pre和cur绑定了，把pre初始化掉
        while (cur)
        {
            ListNode *nxt = cur->next;
            cur->next = pre; // 第一次循环：slow的next改为nullptr
            pre = cur;
            cur = nxt;
        }
        // 反转后，pre就是新的head
        ListNode *head2 = pre;
        // 下面对两段进行归并
        // 由于第二段长度≥第一段，则以第一段为循环判断
        cur = head;
        while (cur)
        {
            // 如果是奇数，cur会比head2更早一步到达nullptr
            ListNode *nxt1 = cur->next, *nxt2 = head2->next;
            cur->next = head2;
            head2->next = nxt1;
            pre = head2;
            cur = nxt1;
            head2 = nxt2;
        }
        // 如果一样长，head2会和cur一起变成nullptr
        // 当退出时，head2有可能还在最后一个结点。
        // 目前slow这个中间结点没串上。这是因为在退出循环后，没有处理
        if (head2)
            pre->next = head2;
    }
};