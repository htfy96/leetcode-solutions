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
    //  (n - l0) % k == (2n - l0) % k
    // n% k = 2 n % k (n % k == 0)
    ListNode *detectCycle(ListNode *head) {
        ListNode* p1 = head, *p2 = head;
        if (!head) return nullptr;
        do {
            if (!p1->next) return nullptr;
            p1 = p1->next;
            if (!p2->next) return nullptr; p2 = p2->next;
            if (!p2->next) return nullptr; p2 = p2->next;
        } while (p1 != p2);
        int cnt = 0;
        for (ListNode* x = head; x != p1; ++cnt) {
            x = x->next;
            p1 = p1->next;
        }
        return p1;
    }
};