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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int lcnt = 0, rcnt = 0;
        for (TreeNode *p = root; p; p = p->left)
            ++lcnt;
        for (TreeNode *p = root; p; p = p->right)
            ++rcnt;
        if (lcnt == rcnt)
            return (1 << lcnt) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};