/*
Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return head;

        for (Node *cur = head; cur; cur = cur->next->next)
            cur->next = new Node(cur->val, cur->next, nullptr);

        for (Node *cur = head; cur; cur = cur->next->next)
        {
            if (cur->random)
                cur->next->random = cur->random->next;
        }

        Node *nhead = head->next;
        Node *cur = head;
        while (cur->next->next)
        {
            Node *copy = cur->next;
            cur->next = copy->next; // 还原
            copy->next = copy->next->next;
            cur = cur->next;
        }
        cur->next = nullptr; // 因为循环退出后cur在长链表的倒数第二个
        // 恰好就是原链表的最后一个，因此next从新链表的最后一个，改为nullptr

        return nhead;
    }
};