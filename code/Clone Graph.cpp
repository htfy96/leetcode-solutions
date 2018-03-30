/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return nullptr;
        queue<UndirectedGraphNode*> q;
        unordered_map<int, UndirectedGraphNode*> m;
        UndirectedGraphNode* head = new UndirectedGraphNode(node->label);
        m[head->label] = head;
        q.push(head);
        head->neighbors = node->neighbors;
        while (!q.empty()) {
            UndirectedGraphNode* x= q.front();
            q.pop();
            //cout << "visiting node = " << x->label << endl;
            for (UndirectedGraphNode*& ch: x->neighbors) {
                auto it = m.find(ch->label);
                if (it == m.end()) {
                    m[ch->label] = new UndirectedGraphNode(ch->label);
                    m[ch->label]->neighbors = ch->neighbors;
                    q.push(m[ch->label]);
                }
                ch = m[ch->label];
            }
        }
        return head;
    }
};