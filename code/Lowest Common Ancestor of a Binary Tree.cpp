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
    pair<bool, bool> search(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (!root) return make_pair(false, false);
        auto result = make_pair(root == p, root == q);
        auto lres = search(root->left, p, q), rres = search(root->right, p, q);
        result.first = result.first || lres.first || rres.first;
        result.second = result.second || lres.second || rres.second;
        if (result.first && result.second) throw root;
        return result;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        try
        {
            search(root, p, q);
        } catch (TreeNode* result)
        {
            return result;
        }
    }
};