/**
运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。
获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
写入数据 put(key, value) - 如果密钥不存在，则写入其数据值。当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
*/
class LRUCache {
public:
    LRUCache(int capacity):__cap(capacity) {
    }

    int get(int key) {
        auto it=mapping.find(key);
        if(it!=mapping.end())
        {
            int value=it->second->second;
            L.erase(it->second);
            L.push_front(make_pair(key,value));
            mapping[key]=L.begin();
            return value;
        }
        return -1;
    }

    void put(int key, int value) {
        auto it=mapping.find(key);
        if(it!=mapping.end())
        {
            L.erase(it->second);
        }
        L.push_front(make_pair(key,value));
        mapping[key]=L.begin();

        if(L.size()>__cap)
        {
            int key=L.back().first;
            mapping.erase(key);
            L.pop_back();
        }
    }
private:
    unordered_map<int,list<pair<int,int>>::iterator> mapping;
    list<pair<int,int>> L;
    int __cap;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */