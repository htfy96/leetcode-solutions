template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}
class Solution {
    struct Node
    {
        unique_ptr<Node> ch[2];
        int cnt = 1;
        int val;
        Node() = default;
        Node(int val, int cnt = 1): val(val), cnt(cnt) {}
    };
    
    void insert(unique_ptr<Node> &root, int val)
    {
        if (!root)
            root = make_unique<Node>(val);
        else
        {
            if (val < root->val)
                insert(root->ch[0], val);
            else if (val > root->val)
                insert(root->ch[1], val);
            ++root->cnt;
        }
    }
    
    int countSmaller(const unique_ptr<Node> &root, int val)
    {
        if (!root) return 0;
        if (val <= root->val)
            return countSmaller(root->ch[0], val);
        else
        {
            int right = root->ch[1] ? root->ch[1]->cnt : 0;
            int cright = countSmaller(root->ch[1], val);
            return root->cnt - (right - cright);
        }
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        unique_ptr<Node> root;
        vector<int> ans(nums.size());
        for (int i=nums.size() - 1; i>=0; --i)
        {
            ans[i] = countSmaller(root, nums[i]);
            insert(root, nums[i]);
        }
        return ans;
    }
};