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
    TreeNode* buildTreeImpl(int* prebegin, int* preend, int* inbegin, int* inend) {
        if (distance(prebegin, preend) == 1)
            return new TreeNode(*prebegin);
        if (prebegin == preend) return nullptr;
        int idx = find(inbegin, inend, *prebegin) - inbegin;
        TreeNode* root = new TreeNode(*prebegin);
        root->left = buildTreeImpl(prebegin + 1, prebegin + 1 + idx, inbegin, inbegin + idx);
        root->right = buildTreeImpl(prebegin + 1 + idx, preend, inbegin + idx + 1, inend);
        return root;
        
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeImpl(preorder.data(), preorder.data() + preorder.size(), inorder.data(), inorder.data() + inorder.size());
    }
};