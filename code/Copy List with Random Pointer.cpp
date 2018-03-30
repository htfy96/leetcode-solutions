/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) return nullptr;
        auto p = head;
        while(p)
        {
            auto oldNext = p->next;
            p->next = new RandomListNode(p->label);
            p->next->next = oldNext;
            p->next->random = p->random;
            p = oldNext;
        }
        p = head->next;
        for (;;)
        {
            p->random = p->random ? p->random->next : nullptr;
            if (!p->next) break;
            p = p->next->next;
        }
        auto newHead = head->next;
        for (p = head; p->next;)
        {
            auto next = p->next;
            p->next = p->next->next;
            p = next;
        }
        return newHead;
    }
};