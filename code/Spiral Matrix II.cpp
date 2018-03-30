class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        static const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        auto valid = [n](int x, int y) -> bool {
            return x>=0 && y>=0 && x<n && y<n;
        };
        
        int dir = 0;
        vector<vector<int>> ans(n, vector<int>(n));
        if (!n) return ans;
        int x = 0, y = 0; int cnt = 0;
        while (!ans[x][y])
        {
            ans[x][y] = ++cnt;
            int trycnt = 0;
            while (!valid(x + dx[dir], y + dy[dir]) || ans[x + dx[dir]][y + dy[dir]]) {
                ++trycnt; if (trycnt > 4) break;
                dir = (dir + 1) % 4;
            }
            if (trycnt > 4) break;

            x += dx[dir]; y+= dy[dir];

        }
        return ans;
    }
};