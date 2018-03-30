class Solution {
public:
    vector<int> fallingSquares(vector<pair<int, int>>& positions) {
        vector<int> poses;
        for (auto&& p: positions) {
            poses.push_back(p.first);
            poses.push_back(p.first + p.second - 1);
        }
        vector<int> ans;
        sort(poses.begin(), poses.end());
        poses.erase(unique(poses.begin(), poses.end()), poses.end());
        vector<int> d(poses.size());
        //cout << "preprocess finished" << endl;
        for (auto&& p: positions) {
            int cur_ans = !ans.empty() ? *ans.rbegin() : 0;
            int start_idx = lower_bound(poses.cbegin(), poses.cend(), p.first) - poses.cbegin(),
                end_idx = lower_bound(poses.cbegin(), poses.cend(), p.first + p.second - 1) - poses.cbegin();
            int max_depth = 0;
            for (int i=start_idx; i<=end_idx; ++i)
                max_depth = max(max_depth, d[i]);
            cur_ans = max(cur_ans, max_depth + p.second);
            for (int i=start_idx; i<=end_idx; ++i)
                d[i] = max_depth + p.second;
            ans.push_back(cur_ans);
        }
        return ans;
    }
};