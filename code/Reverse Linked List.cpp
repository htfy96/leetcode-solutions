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
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        ListNode *newHead = head, *next = head->next; head->next = nullptr;
        while (next)
        {
            ListNode *nextnext = next->next;
            next->next = newHead;
            newHead = next;
            next = nextnext;
        }
        return newHead;
    }
};