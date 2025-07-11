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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        // 由于可能删除头结点，因此需要创建dummy
        ListNode dummy(0, head);
        ListNode *right = &dummy, *left = &dummy;
        for (int i = 0; i < n; i++)
            right = right->next;

        while (right->next)
        {
            right = right->next;
            left = left->next;
        }
        // 当right->next味nullptr，此时right就恰好是最后一个结点，而left与right差n个。
        // 因此left就恰好是要删除节点的前一个结点
        // 很巧妙的定位方法
        ListNode *temp = left->next;
        left->next = temp->next;
        delete temp;
        return dummy.next; // 这里不要return head，因为有可能删除的就是头结点，这样被释放掉了
        // 而dummy可以始终保持是head之前，因为如果删head的话，dummy结点就会更新
    }
};