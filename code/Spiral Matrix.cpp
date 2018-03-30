class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return {};
        const int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        int curdir = 0;
        const int m = matrix.size(), n = matrix[0].size();
        int total_iter = min((m+1)/2, (n+1) / 2);
        #define iter(x, y) (min(min((x), m-1-(x)), min((y), n-1-(y))))
        #define valid(x, y) ((x) >= 0 && (x) <= m && (y) >= 0 && (y) < n)
        int x = 0, y = 0;
        vector<int> ans;
        ans.push_back(matrix[0][0]);
        int total_change = 0;
        #define next_x (x + dx[curdir])
        #define next_y (y + dy[curdir])
        for (;;)
        {
            int fail_cnt = 0;
            while (!(valid(next_x, next_y) && iter(next_x, next_y) >= iter(x, y) && (next_x != iter(x, y) || next_y != iter(x, y))))
            {
                if (++fail_cnt == 2) break;
                curdir = (curdir + 1) % 4;
                ++total_change;
            }
            if (fail_cnt == 2) break;
            if (total_change / 4 != iter(next_x, next_y)) break;
            {
                int nx = next_x, ny = next_y;
                x = nx; y = ny;
                //cout << "x = " << x << " y=" << y << endl;
                ans.push_back(matrix[x][y]);
            }
        }
        return ans;
        
    }
};