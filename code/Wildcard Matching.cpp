class Solution {
public:
    bool isMatch(string s, string p) {
        const int m = s.size(), n = p.size();
        vector<char> f((m+1) * (n+1));
        f[0] = true;
        for (int i=0; i<=m; ++i)
            for (int j=0; j<=n; ++j)
            {
                if (!j) continue;
                const char pattern = p[j-1];
                switch (pattern) {
                    case '?':
                        if (!i) continue;
                        f[i * (n+1) + j] = f[(i-1) * (n+1) + j-1];
                        break;
                    case '*':
                        f[i*(n+1) + j] = f[i * (n+1) + j-1];
                        if (i) f[i*(n+1) + j] = f[i*(n+1) + j] || f[(i-1) * (n+1) + j];
                        break;
                    default:
                        if (!i) continue;
                        f[i * (n+1) +j] = (pattern == s[i-1]) && f[(i-1) * (n+1) + j-1];
                }
            }
        return f[m * (n+1) + n];
    }
};