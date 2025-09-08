struct Node
{
    Node* son[26] {};
    bool end = false;
};

class Trie
{
    Node* root = new Node(); // C++已经直接默认构造函数成功了，自己不用写了

    int find(string word)
    {
        Node* cur = root;
        for (char c : word)
        {
            c -= 'a';
            if (!cur->son[c])
                return 0;
            cur = cur->son[c];
        }
        return cur->end ? 2 : 1; // 2 表示完全匹配，也就是整个单词
        // 1 表示部分匹配，也就是是当前的前缀
    }

    void destroy(Node* node)
    {
        // 递归终止条件，节点为空
        if (!node)
            return;
        // 当前节点不为空，需要递归调用当前节点的子节点，之后在删除自己当前节点
        for (Node* son : node->son) // 要对当前节点所有 son 节点进行递归销毁
            destroy(son);
        delete node;
    }

public:
    ~Trie() // 析构函数因为需要被外部的代码调用来销毁，因此 public
    {
        // 别忘了释放 root
        destroy(root);
    }

    void insert(string word)
    {
        Node* cur = root;
        for (char c : word)
        {
            c -= 'a';
            if (!cur->son[c])
                cur->son[c] = new Node();
            cur = cur->son[c];
        }
        cur->end = true;
    }

    bool search(string word)
    {
        return find(word) == 2;
    }

    bool startsWith(string prefix)
    {
        return find(prefix) != 0; // 不论是前缀还是恰好就是这个单词本身
        // 因为一个单词本身就是自己的前缀
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */