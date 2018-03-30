class Solution {
public:
    int numTrees(int n) {
        vector<long long> a; a.reserve(n + 1);
        for (long long i=0; i<=n; ++i)
        {
            if (i <= 1) { a.push_back(1); continue; }
            long long ans = 0;
            for (long long j=0; j<i; ++j)
                ans += a[j] * a[i - j - 1];
            a.push_back(ans);
        }
        return a[n];
    }
};