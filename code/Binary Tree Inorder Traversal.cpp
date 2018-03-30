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
    vector<int> inorderTraversal(TreeNode* root) {
        if (!root) return {};
        vector<int> l1;
        if (root->left) l1 = inorderTraversal(root->left);
        l1.push_back(root->val);
        if (root->right) {
            vector<int> l2 = inorderTraversal(root->right);
            move(l2.begin(), l2.end(), back_inserter(l1));
        }
        return l1;
    }
};