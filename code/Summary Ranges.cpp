class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<pair<int, int>> res;
        for (int n: nums)
            if (res.empty() || n != res.rbegin()->second + 1)
                res.push_back(make_pair(n, n));
            else
                res.rbegin()->second++;
        vector<string> ans;
        for (auto &&p: res)
            ans.push_back(p.first != p.second ? (to_string(p.first) + "->" + to_string(p.second)) : to_string(p.first));
        return ans;
    }
};