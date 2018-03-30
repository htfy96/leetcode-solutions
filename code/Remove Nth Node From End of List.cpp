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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int l = 0;
        for (auto p = head; p; p = p->next) ++l;
        n = l - n; // 0-based
        ListNode h(0); h.next = head;
        ListNode* p = &h;
        for (;n;n--) p = p->next;
        ListNode* nnext = p->next->next;
        delete p->next;
        p->next = nnext;
        return h.next;
    }
};