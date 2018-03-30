#pragma GCC optimize("-Ofast")
#pragma GCC optimize("-march=native")
class Solution {
public:
    int minDistance(string word1, string word2) {
        const int m = word1.size(), n = word2.size();
        vector<int> f((m+1) * (n+1), INT_MAX);
        #define idx(x, y) ((x) * (n+1) + (y))
        for (int i=0; i<=m; ++i)
            for (int j=0; j<=n; ++j) {
                if (!i && !j) { f[idx(i, j)] = 0; continue; }
                if (i)
                    f[idx(i, j)] = min(f[idx(i, j)], f[idx(i-1, j)] + 1);
                if (j)
                    f[idx(i, j)] = min(f[idx(i, j)], f[idx(i, j-1)] + 1);
                if (i && j)
                    f[idx(i, j)] = min(f[idx(i, j)], f[idx(i-1, j-1)] + (word1[i-1] == word2[j-1] ? 0 : 1));
            }
        return f[idx(m, n)];
    }
};