/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
    template<typename T>
    void visit(TreeNode* p, const T& op) {
        if (!p) return;
        op(p);
        visit(p->left, op);
        visit(p->right, op);
    }
    
    struct Rec {
        int val;
        int l, r;
        TreeNode* ptr = nullptr;
    };
    
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        unordered_map<TreeNode*, int> m;
        m[nullptr] = 0;
        visit(root, [&m](TreeNode* p) {
            int old_cnt = m.size();
            m[p] = old_cnt;
        });
        ostringstream oss;
        visit(root, [&m, &oss](TreeNode *p) {
           oss << p->val << " " << m[p->left] << " " << m[p->right] << " ";
        });
        //cout << oss.str() << endl;
        return oss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        int val, l, r;
        vector<Rec> result;
        while (iss >> val >> l >> r) {
            result.push_back(Rec{ val, l, r, new TreeNode(0)});
        }
        if (result.empty()) return nullptr;
        for (int i=0; i<result.size(); ++i) {
            result[i].ptr->val = result[i].val;
            result[i].ptr->left = result[i].l ? result[result[i].l - 1].ptr : nullptr;
            result[i].ptr->right = result[i].r ? result[result[i].r - 1].ptr : nullptr;
        }
        return result[0].ptr;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));