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
        int total_cnt; // 0 for successful result
        int result;
    };
    
    Rec kthSmallestImpl(TreeNode* root, int k) {
        int total_cnt = 0;
        if (root->left) {
            Rec res = kthSmallestImpl(root->left, k);
            if (!res.total_cnt) return res;
            k -= res.total_cnt;
            total_cnt += res.total_cnt;
        }
        if (!k) return Rec{0, root->val};
        k--; ++total_cnt;
        if (root->right) {
            Rec res = kthSmallestImpl(root->right, k);
            if (!res.total_cnt) return res;
            total_cnt += res.total_cnt;
        }
        return Rec{total_cnt, 0};
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        return kthSmallestImpl(root, k-1).result;
    }
};