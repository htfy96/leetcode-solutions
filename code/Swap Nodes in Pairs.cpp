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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode *newHead = nullptr, *cur = nullptr;
        ListNode *p = head;
        while (p && p->next)
        {
            if (!newHead)
            {
                newHead = new ListNode(p->next->val);
                cur = newHead;
            }
            else
            {
                cur->next = new ListNode(p->next->val);
                cur = cur->next;
            }
            cur->next = new ListNode(p->val);
            p = p->next->next; cur = cur->next;
        }
        if (p)
            cur->next = new ListNode(p->val);
        return newHead;
    }
};