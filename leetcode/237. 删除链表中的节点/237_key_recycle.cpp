class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        auto nxt = node->next;
        *node = *nxt;
        delete nxt;
    }
};