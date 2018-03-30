/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head) return nullptr;
        int len = 0;
        auto x = head; while (x) { ++len; x = x->next; }
        
        auto p = head;
        for (int i=0; i<(len - k % len)%len; ++i)
            p = p->next;
            
        
        auto newHead = new ListNode(p->val);
        
        auto p1 = newHead, p2 = p;
        for (;;)
        {
            auto next = p2->next ? p2->next : head;
            if (next == p)
                break;
            p1->next = new ListNode(next->val);
            p1 = p1->next;
            p2 = next;
        }
        return newHead;
        
    }
};