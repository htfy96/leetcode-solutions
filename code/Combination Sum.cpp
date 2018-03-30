class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<vector<int>>> a((target+1) * 2);
        if (!target) return {{}};
        #define idx(i, j) ((i) % 2 * (target + 1) + (j))
        for (int i=0; i<candidates.size(); ++i)
            for (int j=0; j<=target; ++j)
            {
                a[idx(i, j)].clear();
                if (j >= candidates[i])
                {
                    auto& last = a[idx(i, j- candidates[i])];
                    for (auto&& res: last)
                    {
                        a[idx(i, j)].push_back(res);
                        a[idx(i, j)].rbegin()->push_back(candidates[i]);
                    }
                }
                if (i)
                {
                    auto& last = a[idx(i-1, j)];
                    move(last.cbegin(), last.cend(), back_inserter(a[idx(i, j)]));
                }
                else if (!j)
                    a[idx(i, j)].push_back({});
                //cout << "i=" << i << " j=" << j << "\t size=" << a[idx(i, j)].size() << endl;
            }
        return a[idx(candidates.size() - 1, target)];
    }
};