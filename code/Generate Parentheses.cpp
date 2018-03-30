class Solution {
    unordered_map<int, vector<string>> cache;
public:
    vector<string> generateParenthesis(int n) {
        if (!n) return {""};
        if (cache.find(n) != cache.end()) return cache[n];
        
        vector<vector<string>> f(n+1);
        f[0].push_back("");
        for (int i=1; i<=n; ++i) {
            for (int j=0; j<i; ++j)
            {
                auto vec = generateParenthesis(i-1-j);
                for (auto& s: vec)
                    s = "(" + s + ")";
                for (int k1 = 0; k1<vec.size(); ++k1)
                    for (int k2=0; k2<f[j].size(); ++k2)
                        f[i].push_back(f[j][k2] + vec[k1]);
            }
        }
        cache[n] = f[n];
        return f[n];
    }
};