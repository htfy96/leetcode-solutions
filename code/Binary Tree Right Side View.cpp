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
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return vector<int>();
        vector<int> l = rightSideView(root->left), r = rightSideView(root->right);
        if (l.size() > r.size())
            for (int i = r.size(); i<l.size(); ++i)
                r.push_back(l[i]);
        r.insert(r.begin(), root->val);
        return r;
    }
};