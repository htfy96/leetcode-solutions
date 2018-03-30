/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
    const NestedInteger* ptr, *ed;
    unique_ptr<NestedIterator> ch;
    static int depth;
    //vector<NestedInteger> nestedList;
    void move_to_next_unchecked()
    {
        ++ptr;
        if(ptr != ed && !ptr->isInteger()) ch = make_unique<NestedIterator>(ptr->getList());
    }
    void move_to_next_valid()
    {
        while (ptr != ed && !ptr->isInteger() && !ch->hasNext()) {
            move_to_next_unchecked();
        }
    }
public:
    NestedIterator(const vector<NestedInteger> &nestedList) {
        ptr = nestedList.data(); ed = nestedList.data() + nestedList.size();
        if (ptr != ed && !ptr->isInteger()) ch = make_unique<NestedIterator>(ptr->getList());
        move_to_next_valid();
    }

    int next() {
        assert(ptr != ed);
        int val = 0;
        if (ptr->isInteger()) {
            val = ptr->getInteger();
            move_to_next_unchecked();
        }
        else {
            val = ch->next();
        }
        move_to_next_valid();
        return val;
    }

    bool hasNext() {
        return ptr != ed;
    }
};

int NestedIterator::depth = 0;

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */