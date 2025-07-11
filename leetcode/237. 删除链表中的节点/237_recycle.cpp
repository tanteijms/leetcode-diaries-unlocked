class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        ListNode *toDelete = node->next; // 保存待删除的节点
        node->val = toDelete->val;       // 复制值
        node->next = toDelete->next;     // 跳过待删除节点
        delete toDelete;                 // 释放内存
    }
};