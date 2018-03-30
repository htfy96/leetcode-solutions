/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int get_and_next(ListNode*& p) {
        if (p) {
            int val = p->val; p = p->next; return val;
        } else return 0;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode h(0); ListNode* p = &h;
        int jw = 0;
        while(l1 || l2 || jw) {
            int v1 = get_and_next(l1), v2 = get_and_next(l2);
            p->next = new ListNode((v1 + v2 + jw) % 10);
            p = p->next;
            jw = (v1 + v2 + jw) / 10;
        }
        return h.next;
    }
};