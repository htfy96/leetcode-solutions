class LFUCache {
    struct Item
    {
        int key, value;
        int cnt;
        int last;
        bool free;
    };
    
    Item *a;
    int capacity;
    int G_CNT = 1;
    
    void debug()
    {
        for (int i=0; i<capacity; ++i)
           cout << "["<<i<<"] " << a[i].key << "=" << a[i].value << " free=" << a[i].free << "\t";
        cout << endl;
    }
public:
    LFUCache(int capacity): capacity(capacity) {
        a = new Item[capacity];
        fill(a, a+capacity, Item {0, 0, 0, 0, true});
    }
    
    int get(int key) {
        //debug();
        ++G_CNT;
        auto it = find_if(a, a+capacity, [key](Item item) {
            return !item.free && item.key == key;
        });
        if (it == a + capacity)
        {
            return -1;
        }
        it->last = G_CNT;
        it->cnt++;
        return it->value;
    }
    
    void set(int key, int value) {
        ++G_CNT;
  
        auto free_it = find_if(a, a+capacity, [key](Item item) {
            return item.free || (!item.free && item.key == key);
        });
        
        if (free_it == a+capacity) // full
        {
            auto remove_it = min_element(a, a+capacity, [](Item a, Item b) {
                return a.cnt < b.cnt || (a.cnt == b.cnt && a.last < b.last);
            });
            remove_it->free = true;
            remove_it->cnt = 0;
            free_it = remove_it;
        }
        
        free_it->key = key;
        free_it->value = value;
        ++free_it->cnt;
        free_it->last = G_CNT;
        free_it->free = false;
    }
    
    virtual ~LFUCache()
    {
        delete[] a;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.set(key,value);
 */