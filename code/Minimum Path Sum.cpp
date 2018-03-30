class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        const int m = grid.size(), n = grid[0].size();
        vector<int> d(2 * n, INT_MAX / 2);
        const int dx[] = {0, 1}, dy[] = {1, 0};
        #define valid(i, j) ((i) >= 0 && (i) < m && (j) >= 0 && (j) < n)
        #define idx(i, j) ((i) % 2 * n + (j))
        d[idx(0, 0)] = grid[0][0];
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
              if (i || j)
                  d[idx(i, j)] = min(i ? d[idx(i-1, j)] + grid[i][j] : INT_MAX, j ? d[idx(i, j-1)] + grid[i][j] : INT_MAX);
        return d[idx(m-1, n-1)];
    }
};