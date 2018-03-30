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
    pair<int, int> dp(TreeNode *node) // choose_this
    {
        pair<int, int> lans = make_pair(0, 0), rans = make_pair(0, 0), ans;
        if (node->left)
            lans = dp(node->left);
        if (node->right)
            rans = dp(node->right);
            
        
            ans.first = node->val + lans.second + rans.second;
            ans.second = max(lans.first, lans.second) + max(rans.first, rans.second);
        return ans;
    }
public:
    int rob(TreeNode* root) {
        if (!root) return 0;
        auto ans = dp(root);
        return max(ans.first, ans.second);
    }
};