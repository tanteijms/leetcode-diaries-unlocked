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
    bool hasCycle(ListNode *head)
    {
        // 由于相对速度只有1，那么一定可以追上
        // 存在两种情况：1. 慢到达环起点的时候，快恰好马上到起点，那么很快追上
        // 2. 慢到达起点的时候，快恰好在慢前面一点点，那么相当于快在慢的后面 不到一圈的位置
        // 由于相对速度为1，则快追上慢的时候，慢就刚好走了刚才那 不到一圈的距离
        // 综上，慢进入环以后，快一定是在一圈内，就刚好追上慢了
        ListNode *slow = head, *fast = head;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow)
                return true;
        }
        return false;
    }
};