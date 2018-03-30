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
    struct Rec {
        int mi, ma;
        bool valid;
    };
    
    Rec f(TreeNode* p) {
        assert(p);
        Rec result {p->val, p->val, true};
        if (p->left) {
            const Rec lres = f(p->left);
            if (lres.ma >= p->val || !lres.valid) result.valid = false;
            result.mi = min(result.mi, lres.mi);
            result.ma = max(result.ma, lres.ma);
        }
        if (p->right) {
            const Rec rres = f(p->right);
            if (rres.mi <= p->val || !rres.valid) result.valid = false;
            result.mi = min(result.mi, rres.mi);
            result.ma = max(result.ma, rres.ma);
        }
        return result;
    }
public:
    bool isValidBST(TreeNode* root) {
        if (!root) return true;
        Rec result = f(root);
        return result.valid;
    }
};