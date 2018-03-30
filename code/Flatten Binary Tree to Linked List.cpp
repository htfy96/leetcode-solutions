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
    void flatten(TreeNode* root) {
        if (!root) return;
        if (root->right) flatten(root->right);
        if (root->left) {
            flatten(root->left);
            TreeNode* p = root->right;
            root->right = root->left;
            root->left = nullptr;
            TreeNode* x = root->right;
            while (x->right) x = x->right;
            x->right = p;
        }
    }
};