/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        queue<pair<TreeLinkNode*, int>> q;
        if (!root) return;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            auto x = q.front();
            TreeLinkNode* ptr = x.first; int depth = x.second;
            q.pop();
            if (!q.empty() && q.front().second == depth) ptr->next = q.front().first;
            else ptr->next = nullptr;
            if (ptr->left) q.push(make_pair(ptr->left, depth + 1));
            if (ptr->right) q.push(make_pair(ptr->right, depth + 1));
        }
    }
};