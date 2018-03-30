class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        using ULL = unsigned long long;
        unordered_set<ULL> hashes;
        int maxlen = 0;
        reverse(s.begin(), s.end());
        for (string& w: wordDict)
            reverse(w.begin(), w.end());
        for (auto&& word: wordDict)
        {
            ULL x = 0;
            for (int i=word.size() - 1; i>=0; --i)
                x = x * 131 + word[i];
            maxlen = max(maxlen, (int)word.size() );
            hashes.insert(x);
        }
        vector<vector<string>> f(s.size() + 1);
        f[0].push_back("");
        
        vector<bool> ok(s.size()  + 1);
        ok[0] = true;
        for (int i=1; i<=s.size(); ++i)
        {
            ULL u = 0;
            for (int j=1; j<=min(i, maxlen); ++j)
            {
                u = u * 131 + s[i-j];
                if (hashes.find(u) != hashes.end())
                    ok[i] = ok[i] | ok[i-j];
            }
        }
        if (!ok[s.size()]) return {};
        for (int i=1; i<=s.size(); ++i)
        {
            ULL u = 0;
            for (int j=1; j<=min(i, maxlen); ++j)
            {
                u = u * 131 + s[i-j];
                if (hashes.find(u) != hashes.end()) {
                    for (auto&& last_str: f[i-j])
                        f[i].push_back(last_str.empty() ? s.substr(i-j, j) : last_str + " " + s.substr(i-j, j));
                }
            }
        }
        for (string& ans: f[s.size()])
            reverse(ans.begin(), ans.end());
        return f[s.size()];
        
        
    }
};