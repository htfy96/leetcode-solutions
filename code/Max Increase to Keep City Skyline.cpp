class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;
        const int m = grid.size(), n = grid[0].size();
        vector<int> high_row(m), high_col(n);
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
            {
                high_row[i] = max(high_row[i], grid[i][j]);
                high_col[j] = max(high_col[j], grid[i][j]);
            }
        int ans = 0;
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
                ans += min(high_row[i], high_col[j]) - grid[i][j];
        return ans;
    }
};