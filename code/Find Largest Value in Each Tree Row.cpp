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
    void run(TreeNode *node, int depth, vector<int> &ans)
    {
        if (ans.size() < depth)
            ans.push_back(node->val);
        else
            ans[depth - 1] = max(ans[depth-1], node->val);
        if (node->left) run(node->left, depth+1, ans);
        if (node->right) run(node->right, depth+1, ans);
    }
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root) return vector<int>();
        vector<int> ans;
        run(root, 1, ans);
        return ans;
        
    }
};