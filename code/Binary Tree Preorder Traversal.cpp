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
    struct Frame
    {
        TreeNode *cur;
        int stage = 0;
        Frame *parent = nullptr;
        vector<int> init_res;
        Frame(TreeNode *cur, int stage, Frame *parent):
            cur(cur), stage(stage), parent(parent)
            {}
        Frame() = default;
    };
    
    
    
    vector<int> traverse(TreeNode *root)
    {
        stack<Frame> s;
        Frame init_frame;
        s.push(Frame (root, 0, &init_frame));
        while (!s.empty())
        {
            Frame &x = s.top();
            cout << s.size() << " " << (void*)&x <<": cur=" << (void*)x.cur << " stage=" << x.stage <<" parent=" << (void*)x.parent << endl;
            switch(x.stage) {
                case 0:
                    if (!x.cur) { s.pop(); break; }
                    x.init_res.push_back(x.cur->val);
                    if (x.cur->left)
                    {
                        x.stage = 1;
                        s.push(Frame (x.cur->left, 0, &x));
                        break;
                    }
                case 1:
                    if (x.cur->right)
                    {
                        x.stage = 2;
                        s.push(Frame (x.cur->right, 0, &x));
                        break;
                    }
                case 2:
                    if (x.parent)
                        copy(x.init_res.begin(), x.init_res.end(), back_inserter(x.parent->init_res));
                    s.pop();
                    break;
            }
        }
        return init_frame.init_res;
    }
public:

    vector<int> preorderTraversal(TreeNode* root) {
        return traverse(root);
    }
};