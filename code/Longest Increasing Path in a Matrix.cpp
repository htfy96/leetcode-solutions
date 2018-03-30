class Solution {
    struct Rec {
        int x, y;
    };
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.empty()) return 0;
        vector<vector<int>> maxl(matrix.size(), vector<int>(matrix[0].size()));
        const int m = matrix.size(), n = matrix[0].size();
        queue<Rec> q;
        vector<bool> v(m * n);
        #define valid(x, y) ((x) >= 0 && (y) >= 0 && (x) < m && (y) < n)
        static const int dx[] = {0, 0, -1, 1};
        static const int dy[] = {-1, 1, 0, 0};
        for (int x=0; x<m; ++x)
            for (int y=0; y<n; ++y)
            {
                bool is_top = true;
                for (int k=0; k<4; ++k)
                    if (valid(x + dx[k], y + dy[k])) {
                        if (matrix[x + dx[k]][y + dy[k]] > matrix[x][y])
                            is_top = false;
                    }
                if (is_top) {
                    maxl[x][y] = 1;
                    v[x * n + y] = true;
                    q.push(Rec { x, y} );
                }
            }
        
        int ans = 0;
        while (!q.empty()) {
            Rec w = q.front();
            q.pop();
            ans = max(ans, maxl[w.x][w.y]);
            //cout << w.x << " " << w.y << " " << maxl[w.x][w.y] << endl;
            for (int k=0; k<4; ++k)
            {
                int newx = w.x + dx[k], newy = w.y + dy[k];
                if (valid(newx, newy) && matrix[newx][newy] < matrix[w.x][w.y]) {
                    maxl[newx][newy] = max(maxl[newx][newy], maxl[w.x][w.y] + 1);
                    if (!v[newx * n + newy])
                    {
                        v[newx * n + newy] = true;
                        q.push(Rec {newx, newy});
                    }
                }
            }
            v[w.x * n + w.y] = false;
        }
        return ans;
    }
};