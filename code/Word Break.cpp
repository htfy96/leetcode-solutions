class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<char> f(s.size());
        using ULL = unsigned long long;
        unordered_set<ULL> ss;
        for (auto&& w: wordDict) {
            ULL x = 0;
            for (int i=w.size() - 1; i>=0; --i)
                x = x * 131 + w[i];
            ss.insert(x);
        }
        for (int i=0; i<s.length(); ++i) {
            ULL x = 0;
            for (int j=i; j>=0; --j) {
                x = x * 131 + s[j];
                if (ss.find(x) != ss.end())
                    f[i] = f[i] || (j ? f[j-1] : true);
            }
        }
        return f[s.size() - 1];
    }
};