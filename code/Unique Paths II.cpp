class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.empty()) return 1;
        const int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> f(2 * n);
        #define idx(a, b) ((((a) + 2) % 2) * n + (b))
        if (!obstacleGrid[0][0]) f[idx(0, 0)] = 1;
        #define valid(x, y) ((x) >= 0 && (x) < m && (y) >=0 && (y) < n)
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j) {
                if (!i && !j) continue;
                f[idx(i, j)] = 0;
                if (obstacleGrid[i][j]) continue;
                if (valid(i-1, j)) f[idx(i, j)] += f[idx(i-1, j)];
                if (valid(i, j-1)) f[idx(i, j)] += f[idx(i, j-1)];
            }
        return f[idx(m-1 , n-1)];
    }
};