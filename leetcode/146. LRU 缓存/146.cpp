struct Node
{
    int key;
    int value;
    Node *prev;
    Node *next;

    Node(int k = 0, int v = 0) : key(k), value(v) {}
};

class LRUCache
{
private:
    int capacity;
    Node *dummy;
    unordered_map<int, Node *> key2node;

    void remove(Node *x)
    {
        x->prev->next = x->next;
        x->next->prev = x->prev;
        // 这里没有delete x，因为考虑比如我们可能是挪位置，
        // 因此x这个结点还需要，只是不在原来链表上的位置了
        // 传入的就是引用，本质上是可以delete的
    }

    void push_front(Node *x)
    {
        x->prev = dummy;
        x->next = dummy->next;
        x->prev->next = x;
        x->next->prev = x;
    }

    Node *get_node(int key)
    {
        auto it = key2node.find(key);
        if (it == key2node.end())
            return nullptr;
        Node *node = it->second;
        remove(node);
        push_front(node); // 获取，就为最新
        return node;
    }

public:
    LRUCache(int capacity) : capacity(capacity), dummy(new Node)
    {
        dummy->prev = dummy;
        dummy->next = dummy; // 构造函数初始化
    }

    int get(int key)
    {
        Node *node = get_node(key);
        return node ? node->value : -1;
    }

    void put(int key, int value)
    {
        Node *node = get_node(key);
        if (node)
        {
            node->value = value;
            return;
        }
        // 不存在key-value这对键值对
        node = new Node(key, value);
        key2node[key] = node;
        push_front(node);
        if (key2node.size() > capacity)
        {
            Node *back_node = dummy->prev;
            key2node.erase(back_node->key);
            remove(back_node);
            delete back_node;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */