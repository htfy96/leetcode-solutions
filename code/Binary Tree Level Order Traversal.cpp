/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> ans;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        while (!q.empty()) {
            auto x = q.front();
            q.pop();
            int lev = x.second;
            if (ans.size() <= lev) ans.resize(lev + 1);
            ans[lev].push_back(x.first->val);
            if (x.first->left)
                q.push(make_pair(x.first->left, x.second + 1));
            if (x.first->right)
                q.push(make_pair(x.first->right, x.second + 1));
        }
        return ans;
    }
};