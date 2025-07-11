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
    bool isPalindrome(ListNode *head)
    {
        if (!head->next)
            return true;
        // 思路：先找重点，然后反转后半段，两边同时开始遍历。
        // 这样不开辟新空间（如果栈的话，空间复杂up）。而时间就是O(n)
        ListNode *slow = head, *fast = head, *pre = nullptr;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            pre = slow;
            slow = slow->next;
        }
        if (pre)
            pre->next = nullptr; // 断开，但是要注意pre是否是nullptr
        ListNode *cur = nullptr;
        if (!fast) // 当总体为偶数时，需要加上slow这个结点。而偶数的情况是，fast自身是nullptr
            cur = slow;
        else // 如果原本总共是奇数个，就不用管slow这个中间结点，不会影响回文的判断
            cur = slow->next;

        pre = nullptr;
        // 下面进行后半段的反转
        while (cur)
        {
            ListNode *nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
        }
        // 到达最后，pre就是尾结点
        // 下面两边同时开始遍历，只要一个不相等，就false
        // 有一个问题是，偶数的话，这样没问题。如果是奇数的话，slow对应的被判定给后半段了
        // 可以利用fast的状态来判断一下，要不要加上slow这个结点【已处理】
        ListNode *head2 = pre; // 考虑如果只有一个元素
        while (head)           // 我确保了head和head2，这两段的长度是一样的
        {
            if (head->val != head2->val)
                return false;

            // 一样的话，要移动指针【勿忘！】
            head = head->next;
            head2 = head2->next;
        }
        return true;
    }
};