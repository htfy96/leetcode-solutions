class Trie {
    struct Node {
        vector<pair<char, Node*>> ch;
        bool terminal = false;
        Node(): terminal(false) { ch.reserve(8); }
    };
    Node h;
public:
    /** Initialize your data structure here. */
    Trie() {
        h = Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* p = &h;
        for (char c: word) {
            auto it = find_if(p->ch.begin(), p->ch.end(), [c](auto&& p) { return p.first == c; });
            if (it == p->ch.end()) {
                p->ch.push_back(make_pair(c, new Node));
                p = p->ch.rbegin()->second;
            } else
                p = it->second;
        }
        p->terminal = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* p = &h;
        for (char c: word) {
            auto it = find_if(p->ch.begin(), p->ch.end(), [c](auto&& p) { return p.first == c;});
            if (it == p->ch.end()) return false;
            p = it->second;
        }
        return p->terminal;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* p = &h;
        for (char c: prefix) {
            auto it = find_if(p->ch.begin(), p->ch.end(), [c](auto&& p) { return p.first == c;});
            if (it == p->ch.end()) return false;
            p = it->second;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie obj = new Trie();
 * obj.insert(word);
 * bool param_2 = obj.search(word);
 * bool param_3 = obj.startsWith(prefix);
 */