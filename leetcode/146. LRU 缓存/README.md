# [146. LRU 缓存](https://leetcode.cn/problems/lru-cache/)



## 题目

请你设计并实现一个满足 [LRU (最近最少使用) 缓存](https://baike.baidu.com/item/LRU) 约束的数据结构。

实现 `LRUCache` 类：

- `LRUCache(int capacity)` 以 **正整数** 作为容量 `capacity` 初始化 LRU 缓存
- `int get(int key)` 如果关键字 `key` 存在于缓存中，则返回关键字的值，否则返回 `-1` 。
- `void put(int key, int value)` 如果关键字 `key` 已经存在，则变更其数据值 `value` ；如果不存在，则向缓存中插入该组 `key-value` 。如果插入操作导致关键字数量超过 `capacity` ，则应该 **逐出** 最久未使用的关键字。

函数 `get` 和 `put` 必须以 `O(1)` 的平均时间复杂度运行。

 

**示例：**

```
输入
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
输出
[null, null, null, 1, null, -1, null, -1, 3, 4]

解释
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // 缓存是 {1=1}
lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
lRUCache.get(1);    // 返回 1
lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
lRUCache.get(2);    // 返回 -1 (未找到)
lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
lRUCache.get(1);    // 返回 -1 (未找到)
lRUCache.get(3);    // 返回 3
lRUCache.get(4);    // 返回 4
```

 

**提示：**

- `1 <= capacity <= 3000`
- `0 <= key <= 10000`
- $0 <= value <= 10^5$
- 最多调用 `2 * 105` 次 `get` 和 `put`



## 题解

```cpp
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
```





## points

1. LRU实现依旧要用双向链表，但是为了有O(1)的时间复杂度，要用哈希表存每个结点的迭代器。本质上就是每个结点的指针，或者说引用

   链表是负责维护访问的顺序，体现新旧的关系。而哈希表是突破定位某结点的时间问题

   因为C++STL对双向链表的实现是用STL容器，因此不是指针，而用迭代器

   迭代器就是STL风格的智能指针，更安全、方便

2. std::list<pair<int, int>> cache;

   这是C++STL风格的双向链表，这些结点都会分散在堆上

   头部begin()就是最新，back()是最老。不用end()是因为end返回一个迭代器，指向最后一个元素的后面

   而back()是最后一个元素的引用，可以直接访问数据

   是和front()对应的，它是第0号元素的引用

   begin()也是第0号元素的迭代器

3. 对std::list<pair<int,int>> cache的操作

   .spilce(pos,list,it)O(1)的时间复杂度，把已有的结点挪位置。pos是目标位置迭代器，挪了以后插在pos的前面

   list是来源列表，可以是同一个list

   it是要被搬运的结点的迭代器

   .emplace_front(k,v)，相对于.emplace_back，都是原地构造一个结点

   .pop_back()尾部删除一个结点

4. LRUCache(int capacity) : capacity(capacity) {}

   就是构造函数，:后是成员初始化的列表，initialize list

   这个等价于我去函数体里面写this->capacity = capacity，但这样更高效

5. 对unordered_map进行find(key)，如果找到了就返回value（在这里value是list的一个迭代器，指向那个结点），若没找到就返回.end()。因此通过与end()进行比较来判定查找的结果

6. unordered_map<int, list<pair<int,int>>::iterator>

   这个哈希表的key是int，就是我们LRU缓存的key。

   value是list的迭代器

   而这个list就是我们实现LRU底层的那个双向链表，每个链表的结点都是key,value，因此int,int



下面考虑手写算法实现，不用写那么多的迭代器之类的。

1. 首先定义Node，就是链表里结点Node的定义，不过是双向的，需要保存Node* prev Node* neext

2. 对于LRUCache类

   capacity是初始化时限定的cache容量

   dummy是因为我们经常需要插入头节点，因此作为哨兵

   key2node是一个哈希表，负责从key值到链表内对应node结点的映射关系

3. remove函数，负责把当前传入的结点x，从链表当中原来的位置剥离出来。注意这里不delete，因为可能涉及到挪动结点的操作

   push_front函数，把当前传入的x放置到最新的位置，即dummy的下一个

   get_node函数，把传入的key对应的结点找到进行返回。首先去key2node哈希表里找，如果调用find函数找不到就说明不存在。如果找到了，首先需要把当前这个结点挪动到最新的位置，因为是最近访问的，之后return整个结点

4. LRUCache对象初始化的时候给capacity复制，并创建出本对象的dummy哨兵

   get直接调用刚才的node函数，并根据非空来判断，不为空，就返回node里的值

   put也需要调用get_node函数，如果存在，就直接更新值，并返回；若不存在，就new一个新的，并存入key2node的映射关系里

   同时需要进行判断，如果超出了上限，就在双向链表中删掉最后一个结点，淘汰。

   注意这里对于访问后的更新，都在get_node函数里进行操作过了