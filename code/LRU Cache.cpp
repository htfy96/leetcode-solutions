class LRUCache {
    list<int> l;
    using ITT = typename list<int>::iterator;
    struct Rec {
        int data;
        ITT it;
    };
    unordered_map<int, Rec> um;
    int capacity;
    
public:
    LRUCache(int capacity): capacity(capacity) {
        um.clear(); l.clear();
    }
    
    int get(int key) {
        auto it = um.find(key);
        if (it == um.end()) return -1;
        auto lit = it->second.it;
        l.erase(lit);
        l.insert(l.begin(), key);
        it->second.it = l.begin();
        return it->second.data;
    }
    
    void put(int key, int value) {
        auto it = um.find(key);
        if (it != um.end()) {
            it->second.data = value;
            auto lit = it->second.it;
            l.erase(lit);
            l.insert(l.begin(), key);
            it->second.it = l.begin();
            return;
        }
        um[key] = Rec { value, l.end() };
        l.insert(l.begin(), key);
        um[key].it = l.begin();
        if (l.size() > capacity) {
            auto last = l.end();
            --last;
            int last_key = *last;
            l.erase(last);
            um.erase(last_key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */