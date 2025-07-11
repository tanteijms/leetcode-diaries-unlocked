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
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) // 考虑如何停止循环。
        // 奇数：fast恰好在最后一个结点的时候，结束。此时特征为fast->next==nullptr
        // 偶数：fast在fast->next的时候，结束。此时fast自身就是nullptr
        {
            // 把判断移到while里面去
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};