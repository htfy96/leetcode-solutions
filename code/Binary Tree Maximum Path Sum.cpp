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
    int ans = -100000000;
    int dp(TreeNode *node) // max_chain
    {
        int leftc = 0, rightc = 0;
        if (node->left)
            leftc = max(leftc, dp(node->left));
        if (node->right)
            rightc = max(rightc, dp(node->right));
        ans = max(ans, leftc + rightc + node->val);
        
        return node->val + max(leftc, rightc);
    }
public:
    int maxPathSum(TreeNode* root) {
        ans = -100000000;
        dp(root);
        return ans;
    }
};