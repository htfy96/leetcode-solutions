/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    struct ListIterator {
        ListNode *p;
        ListIterator() {}
        ListIterator(ListNode* x): p(x) {}
        int& operator*() { return p->val; }
        const int& operator*() const { return p->val; }
        int* operator&() { return &p->val; }
        const int* operator&() const { return &p->val; }
        bool operator==(const ListIterator& other) const { return p == other.p; }
        bool operator!=(const ListIterator& other) const { return p != other.p; }
        ListIterator& operator++() { p = p->next; return *this; }  
        ListIterator operator++(int) { auto oldp = p; p = p->next; return oldp; }
        using value_type = int;
        using reference = int&;
        using pointer = int*;
        using difference_type = ptrdiff_t;
        using iterator_category = forward_iterator_tag;
    };
    
    ListNode* sortImpl(ListNode* st, int len) {
        #define print(st, ed) for (ListNode* w = st; w != ed; w = w->next) { cout << w->val << ", ";} cout << endl;
        //cout << "before len=" << len << endl;
        //print(st, nullptr);
        if (st == nullptr)
            return st;
        if (st->next == nullptr)
            return st;
        int midlen = len/2;
        ListNode* beforemid = next(ListIterator(st), midlen - 1).p;
        ListNode* mid = beforemid->next;
        beforemid->next = nullptr;
        
        ListNode* p1 = sortImpl(st, midlen); 
        ListNode* p2 = sortImpl(mid, len - midlen);
        ListNode h(0); ListNode* p = &h;
        while (p1 || p2) {
            if (!p2 || (p1 && p1->val < p2->val)) {
                p->next = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        p->next = nullptr;
        //cout << "after len=" << len << endl;
        //print(h.next, nullptr);
        return h.next;
    }
public:
    ListNode* sortList(ListNode* head) {
        const int len = distance(ListIterator(head), ListIterator(nullptr));
        return sortImpl(head, len);
    }
};