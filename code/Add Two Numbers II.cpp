/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int getSize(ListNode *l)
    {
        int len = 0;
        while (l)
        {
            ++len;
            l = l->next;
        }
        return len;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *prev = new ListNode(0);
        ListNode *head = prev;
        int s1 = getSize(l1), s2 = getSize(l2);
        int pos = max(s1, s2);
        ListNode *p1 = l1, *p2 = l2;
        while (pos > 0)
        {
            int v1 = pos > s1 ? 0 : p1->val;int v2 = pos > s2 ? 0 : p2->val;
            if (pos <= s1) p1 = p1->next; if (pos <= s2) p2 = p2->next;
            --pos;
            int data = v1 + v2;
            cout << "pos = " << pos << " v1=" <<v1 << " v2=" << v2 << endl;
            prev->next = new ListNode(data % 10);
            prev->val += data / 10;
            prev = prev->next;
        }
        for (;;)
        {
            bool ok = false;
            for (ListNode *p = head; p->next; p=p->next)
            {
                if (p->next->val >= 10)
                {
                    p->val += p->next->val / 10;
                    ok = true;
                    p->next->val %= 10;
                }
            }
            if (!ok)
                break;
        }
        while(head->next && head->val == 0)
        {
            auto next = head->next;
            delete head;
            head = next;
        }
        return head;
    }
};