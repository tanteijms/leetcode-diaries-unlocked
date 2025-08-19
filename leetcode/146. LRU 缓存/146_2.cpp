class LRUCache
{
private:
    int capacity;
    list<pair<int, int>> cache_list;                                // pair 里面保存的是 key 和 value
    unordered_map<int, list<pair<int, int>>::iterator> key_to_iter; // key -> 链表节点迭代器

public:
    LRUCache(int capacity) : capacity(capacity) {}

    int get(int key)
    {
        auto umap_iter = key_to_iter.find(key);
        if (umap_iter == key_to_iter.end())
        { // 没有这本书
            return -1;
        }
        auto list_iter = umap_iter->second; // 有这本书
        // 把这本书（list_iter）从书堆（cache_list）中抽出来，放到最上面（cache_list.begin()）
        cache_list.splice(cache_list.begin(), cache_list, list_iter);
        return list_iter->second; // 返回这本书的 value
    }

    void put(int key, int value)
    {
        auto umap_iter = key_to_iter.find(key);
        if (umap_iter != key_to_iter.end())
        { // 有这本书
            auto list_iter = umap_iter->second;
            list_iter->second = value; // 更新 value
            // 把这本书（list_iter）从书堆（cache_list）中抽出来，放到最上面（cache_list.begin()）
            cache_list.splice(cache_list.begin(), cache_list, list_iter);
            return;
        }
        // 新书，放到最上面（emplace_front）
        cache_list.emplace_front(key, value);
        key_to_iter[key] = cache_list.begin();
        // 书太多了
        if (key_to_iter.size() > capacity)
        {
            // 去掉最后一本书
            key_to_iter.erase(cache_list.back().first);
            cache_list.pop_back();
        }
    }
};