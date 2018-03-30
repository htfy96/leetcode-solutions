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
    vector<vector<int>> calc(TreeNode *node, int sum)
    {
        if (!node->left && !node->right)
            return sum == node->val ? vector<vector<int>> { vector<int> { node->val } } : vector<vector<int>>();
        vector<vector<int>> ans;
        if (node->left)
        {
            auto v1 = calc(node->left, sum - node->val);
            for_each(v1.begin(), v1.end(), [&](vector<int> &v) { v.insert(v.begin(), node->val); });
            ans = move(v1);
        }
        if (node->right)
        {
            auto v2 = calc(node->right, sum - node->val);
            for_each(v2.begin(), v2.end(), [&](vector<int> &v) { v.insert(v.begin(), node->val); });
            move(v2.begin(), v2.end(), back_inserter(ans));
        }
        return ans;
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (!root) return vector<vector<int>>();
        return calc(root, sum);
    }
};