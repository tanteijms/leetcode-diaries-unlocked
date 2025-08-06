# [138. 随机链表的复制](https://leetcode.cn/problems/copy-list-with-random-pointer/)



## 题目

给你一个长度为 `n` 的链表，每个节点包含一个额外增加的随机指针 `random` ，该指针可以指向链表中的任何节点或空节点。

构造这个链表的 **[深拷贝](https://baike.baidu.com/item/深拷贝/22785317?fr=aladdin)**。 深拷贝应该正好由 `n` 个 **全新** 节点组成，其中每个新节点的值都设为其对应的原节点的值。新节点的 `next` 指针和 `random` 指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。**复制链表中的指针都不应指向原链表中的节点** 。

例如，如果原链表中有 `X` 和 `Y` 两个节点，其中 `X.random --> Y` 。那么在复制链表中对应的两个节点 `x` 和 `y` ，同样有 `x.random --> y` 。

返回复制链表的头节点。

用一个由 `n` 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 `[val, random_index]` 表示：

- `val`：一个表示 `Node.val` 的整数。
- `random_index`：随机指针指向的节点索引（范围从 `0` 到 `n-1`）；如果不指向任何节点，则为 `null` 。

你的代码 **只** 接受原链表的头节点 `head` 作为传入参数。

 

**示例 1：**

![img](./assets/e1.png)

```
输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
```

**示例 2：**

![img](./assets/e2.png)

```
输入：head = [[1,1],[2,1]]
输出：[[1,1],[2,1]]
```

**示例 3：**

**![img](./assets/e3.png)**

```
输入：head = [[3,null],[3,0],[3,null]]
输出：[[3,null],[3,0],[3,null]]
```

 

**提示：**

- `0 <= n <= 1000`
- $-10^4 <= Node.val <= 10^4$
- `Node.random` 为 `null` 或指向链表中的节点。



## 题解

```cpp
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
```



## points

1. 不需要哈希表，记录+维护有点复杂

   可以直接在原来的表上进行操作

2. 对于原链表的每一个结点，在他们的后面插入一个新new的结点，值和原结点一样，next是原结点的next，random先nulptr，之后二次遍历时改为与原结点一样。并把原结点的next改为这个新new的结点

   第二次遍历的时候，交叉链表已经建立完毕了。因此这时候再判断原结点有无random，如果有，就按照相同的规则，让新结点的random=原结点的random的下一个，恰好就是原指向原，副本指向副本

3. 还需要遍历一遍，把新旧链表分离出来

   这里遍历每一个原结点，创建其后置新节点的拷贝，并把cur当前结点的next改为原来的正常后继（题目要求不能更改）。而分离出来的新结点，其next也要改为目标的next