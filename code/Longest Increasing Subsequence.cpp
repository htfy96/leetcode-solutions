class Solution {
    class FenwickTree
    {
        vector<int> v;
        static int lowbit(int x)
        {
            return x & (-x);
        }
        public:
        FenwickTree(int size):v(size) {}
        void update(int pos, int val)
        {
            while (pos < v.size())
            {
                v[pos] = max(v[pos], val);
                pos += lowbit(pos);
            }
        }
        
        int get_max(int pos)
        {
            int ans = 0;
            for (int w = pos; w > 0; w -= lowbit(w))
                ans = max(ans, v[w]);
            return ans;
        }
    };
    
    
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<pair<int, int>> vp;
        for (int i=0; i<nums.size(); ++i)
            vp.push_back(make_pair(i, nums[i]));
        sort(vp.begin(), vp.end(), [](const auto& p1, const auto& p2) { return p1.second < p2.second; });
        int m = 1;
        for (int i=0; i<vp.size(); ++i)
        {
            if (i && vp[i].second != vp[i-1].second) ++m;
            nums[vp[i].first] = m;
        }
        //for (int v: nums) cout << v << " "; cout << endl;
        FenwickTree ft(nums.size() + 1);
        int ans = 0;
        for (int v: nums)
        {
            int curans = ft.get_max(v-1) + 1;
            ans = max(ans, curans);
            ft.update(v, curans);
        }
        return ans;
    }
};