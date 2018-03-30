class Solution {
    using CntT = array<int, 26>;
    static size_t h(const CntT& v) {
        size_t ans = 0;
        for (auto&& w: v) { ans = ans * 131 + w; }
        return ans;
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<CntT, vector<string>, decltype(&h)> m(256, &h);
        for (auto&& s: strs) {
            CntT cnt {};
            for (char c: s) cnt[c-'a']++;
            m[cnt].push_back(move(s));
        }
        vector<vector<string>> ans; ans.reserve(m.size());
        for (auto&& item: m) {
            ans.push_back(move(item.second));
        }
        return ans;
    }
};