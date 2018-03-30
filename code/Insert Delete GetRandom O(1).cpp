class RandomizedSet {
    vector<int> v;
    int hole = 0;
    unordered_map<int, int> m;
    static constexpr int kMagic = 19260711;
    void gc() {
        v.clear();
        for (auto&& w: m) {
            v.push_back(w.first);
            w.second = v.size() - 1;
        }
        hole = 0;
    }
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        m.clear();
        hole = 0;
        v.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m.find(val) != m.end()) return false;
        v.push_back(val);
        m[val] = v.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (m.find(val) == m.end()) return false;
        int idx = m[val];
        v[idx] = kMagic;
        m.erase(val);
        if (++hole > (v.size() + 1) / 2) gc();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        for (;;) {
            int rand_idx = rand() % v.size();
            if (v[rand_idx] == kMagic) continue;
            return v[rand_idx];
        }
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */