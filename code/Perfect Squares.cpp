class Solution {
public:
    int numSquares(int n) {
        vector<int> f(n + 1, INT_MAX / 2);
        f[0] = 0;
        for (int i=1; i * i <=n; ++i)
        {
            int p = i*i;
            for (int j = p; j<=n; ++j)
                f[j] = min(f[j], f[j-p] + 1);
        }
        return f[n];
    }
};