/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#pragma GCC optimize("-Ofast")
#pragma GCC target ("arch=skylake-avx512")
class Solution {
    TreeNode* lastptr = nullptr;
    
    TreeNode* first_dec_ptr = nullptr, *first_dec_next_ptr = nullptr,
        *second_dec_ptr = nullptr, *second_dec_next_ptr = nullptr;
    void traverse(TreeNode* root)
    {
        if (root->left)
            traverse(root->left);
        if (lastptr && root->val < lastptr->val) {
            if (!first_dec_ptr)
            {
                first_dec_ptr = lastptr;
                first_dec_next_ptr = root;
            } else {
                second_dec_ptr = lastptr;
                second_dec_next_ptr = root;
            }
        }
        lastptr = root;
        if (root->right)
            traverse(root->right);
    }
public:
    void recoverTree(TreeNode* root) {
        traverse(root);
        if (!second_dec_ptr)
            swap(first_dec_ptr->val, first_dec_next_ptr->val);
        else
            swap(first_dec_ptr->val, second_dec_next_ptr->val);
        
    }
};