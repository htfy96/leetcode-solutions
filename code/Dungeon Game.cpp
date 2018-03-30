class Solution {
    static bool ok(const vector<vector<int>> &dungeon, int k)
    {
        static const int dx[] = {-1, 0}, dy[] = {0, -1};
        const int m = dungeon.size(), n = dungeon[0].size();
        if (dungeon[0][0] + k <=0)
            return false;
        vector<vector<int>> f(m, vector<int>(n, -10000000));
        f[0][0] = dungeon[0][0] + k;
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
                if (i || j)
                    for (int k=0; k<2; ++k)
                    {
                        int ox = i + dx[k], oy = j + dy[k];
                        if (ox >= 0 && ox < m && oy >=0 && oy < n)
                            if (f[ox][oy] + dungeon[i][j] > 0)
                                f[i][j] = max(f[i][j], f[ox][oy] + dungeon[i][j]);
                    }
      //  cout << "k= " << k << " ok=" << f[m-1][n-1] << endl;
        return f[m-1][n-1] > 0;
    }
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int l = 1, r = INT_MAX / 4;
        while (l < r-1)
        {
            int mid = (l + r) / 2;
            if (ok(dungeon, mid))
                r = mid;
            else
                l = mid + 1;
        }
        for (int i=l; i<=r; ++i)
            if (ok(dungeon, i))
                return i;
    }
};