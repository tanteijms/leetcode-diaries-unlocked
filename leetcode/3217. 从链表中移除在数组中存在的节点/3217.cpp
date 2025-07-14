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
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        unordered_map<int, int> freq;
        for (int a : nums)
            freq[a]++;

        ListNode dummy(0, head);
        ListNode *cur = &dummy;
        while (cur->next)
        {
            if (freq[cur->next->val])
                cur->next = cur->next->next;
            else
                cur = cur->next;
        }
        return dummy.next;
    }
};