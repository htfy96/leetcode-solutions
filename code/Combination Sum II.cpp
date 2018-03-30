class Solution {
    size_t hash(const vector<int> &v)
    {
        size_t ans = 0;
        for (int item: v)
        {
            ans ^= item;
        }
        return ans;
    }
    
    vector<vector<int>> calc(vector<int> &v, int k, int target)
    {
        if (k==0)
            if (target)
                return vector<vector<int>>();
            else
                return vector<vector<int>>(1, vector<int>());
                
        vector<vector<int>> ans = calc(v, k-1, target);
        if (v[k-1] <= target)
        {
            auto other = calc(v, k-1, target - v[k-1]);
            for (auto &res: other)
            {
                res.push_back(v[k-1]);
                sort(res.begin(), res.end());
            }
            move(other.begin(), other.end(), back_inserter(ans));
        }
       // cout << "k=" << k << " target=" << target << " anssize=" << ans.size() << endl;
        
        sort(ans.begin(), ans.end(), [&](const vector<int> &a, const vector<int> &b) {
            if (a.size() != b.size()) return a.size() < b.size();
            for (int i=0; i<a.size(); ++i)
                if (a[i] != b[i])
                    return a[i] < b[i];
            return false;
        });
        
        auto ed = unique(ans.begin(), ans.end(), [&](const vector<int>&a, const vector<int> &b) {
           if (a.size() != b.size()) return false;
           for (int i=0; i<a.size(); ++i)
            if (a[i] != b[i])
                return false;
            return true;
        });
        ans.erase(ed, ans.end());
        return ans;
        
    }
    
    
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        return calc(candidates, candidates.size() ,target);
    }
};