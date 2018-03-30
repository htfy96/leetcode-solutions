/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    static bool nextSame(ListNode *p)
    {
        return p->next && p->next->val == p->val;
    }
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;
        
        ListNode *h {}, *cur {};
        ListNode *p = head;
        while (p)
        {
            if (nextSame(p))
            {
                while(p && nextSame(p))
                    p = p->next;
                if (p) p = p->next;
            } else 
            {
                if (cur)
                {
                    cur->next = new ListNode(p->val);
                    cur = cur->next;
                } else 
                {
                    h = new ListNode(p->val); cur = h;
                }
                p = p->next;
            }
        }
        return h;
    }
};