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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return nullptr;
        ListNode h(0);
        ListNode *p = head, *p2 = &h;
        for (;;)
        {
            if (!p->next) break;
            p2->next = p->next;
            p2 = p2->next;
            p->next = p->next->next;
            if (!p->next) break;
            p = p->next;
        }
        p2->next = nullptr;
        p->next = h.next;
        return head;
    }
};