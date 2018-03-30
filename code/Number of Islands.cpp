class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        const int m = grid.size(), n = grid[0].size();
        const int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
        #define valid(x, y) ((x) >= 0 && (x) < m && (y) >= 0 && (y) < n)
        int cnt = 0;
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
                if (grid[i][j] == '1')
                {
                    grid[i][j] = 'x';
                    queue<pair<int, int>> q;
                    ++cnt;
                    q.push(make_pair(i, j));
                    while (!q.empty())
                    {
                        auto x = q.front();
                        q.pop();
                        for (int k=0; k<4; ++k)
                        {
                            int nx = x.first + dx[k], ny = x.second + dy[k];
                            if (valid(nx, ny) && grid[nx][ny] == '1')
                            {
                                grid[nx][ny] = 'x';
                                q.push(make_pair(nx, ny));
                            }
                        }
                    }
                }
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
                if (grid[i][j] == 'x')
                    grid[i][j] = '1';
        return cnt;
    }
};