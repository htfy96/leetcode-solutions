class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        if (matrix.empty()) return -1;
        const int m = matrix.size(), n = matrix[0].size();
        vector<int> a(m*n), s(m*n);
        int ans = -1000;
        
        for (int d = 0; d<m; ++d)
        {
            for (int i=d; i<m; ++i)
                for (int j=0; j<n; ++j)
                {
                    a[i*n+j] += matrix[i-d][j];
                    if (j == 0) s[i*n+j] = a[i*n+j]; else s[i*n+j] = s[i*n+j-1] + a[i*n+j];
                }
            for (int i=0; i<m-d; ++i)
            {
                set<int> ss; ss.insert(0);
                // Sum = S_this - S_prev <= k => S_prev >= S_this - k
                for (int j=0; j<n; ++j)
                {
                    int x = i + d;
                    int S = s[x*n+j];
                    auto it = ss.lower_bound(S - k);
                    if (it != ss.end()) ans = max(ans, S - *it);
                    ss.insert(S);
                }
            }
        }
        return ans;
    }
};