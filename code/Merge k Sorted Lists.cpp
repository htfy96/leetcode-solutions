/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    struct Rec
    {
        int data;
        int idx;
        bool operator<(const Rec& other) const {
            return data < other.data;
        }
        bool operator>(const Rec& other) const {
            return data > other.data;
        }
        bool operator==(const Rec& other) const {
            return data == other.data;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<Rec, vector<Rec>, greater<Rec>> pq;
        vector<ListNode*> nodes;
        for (auto&& node: lists) { 
            nodes.push_back(node);
            if (node) {
                pq.push(Rec{node->val, static_cast<int>(&node - lists.data())});
            }
        }
        ListNode* head = new ListNode(0);
        ListNode* p = head;
        while (!pq.empty())
        {
            Rec t = pq.top();
            pq.pop();
            p->next = new ListNode(nodes[t.idx]->val);
            p = p->next;
            if (nodes[t.idx]->next) {
                nodes[t.idx] = nodes[t.idx]->next;
                pq.push(Rec{nodes[t.idx]->val, t.idx});
            }
        }
        delete head;
        return head->next;
    }
};