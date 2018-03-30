class Solution {
    struct Rec
    {
        int val, pos;
    };
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<Rec> v; v.reserve(nums.size());
        for (int i=0; i<nums.size(); ++i)
            v.push_back(Rec {nums[i], i});
        
        sort(v.begin(), v.end(), [](const Rec &r1, const Rec &r2) { return r1.val > r2.val; });
        int lastfrom = 0;
        set<int> s;
        vector<int> ans(nums.size());
        
        for (int i=0; i<v.size(); ++i)
        {
            Rec x = v[i];
            auto it = s.upper_bound(x.pos);
            if (it != s.end())
                ans[x.pos] = nums[*it];
            else
            {
                auto it2 = s.begin();
                if (it2 != s.end())
                    ans[x.pos] = nums[*it2];
                else
                    ans[x.pos] = -1;
            }
            if (i < v.size() - 1 && v[i].val > v[i+1].val)
            {
                for (int j = lastfrom; j<=i; ++j)
                    s.insert(v[j].pos);
                lastfrom = i+1;
            }
        }
        
        return ans;
        
    }
};