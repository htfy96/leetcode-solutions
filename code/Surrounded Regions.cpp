class Solution {
    #pragma GCC optimize("O2")
    using Grid = vector<vector<char>>;
    
    inline static bool valid(int x, int y, const Grid &g)
    {
        return x>=0 && y>=0 && x < g.size() && y < g[0].size();
    }
    
    vector<vector<bool>> vv;
    
    void fill(int x, int y, Grid &g)
    {
        cout << "Called at " << x <<" " << y << endl;
        static const int dx[] = {0, 0, -1, 1};
        static const int dy[] = {1, -1, 0, 0};
        queue<pair<int, int>> p;
        p.push(make_pair(x, y));
        
        bool ok = true;
        set<pair<int, int>> v;
        v.insert(make_pair(x, y));
        vv[x][y] = true;
        
        while (!p.empty())
        {
            pair<int, int> cur = p.front();
            p.pop();
            
            for (int i=0; i<4; ++i)
            {
                if (valid(cur.first + dx[i], cur.second + dy[i], g))
                {
                    int newx = cur.first + dx[i], newy = cur.second + dy[i];
                    if (g[newx][newy] == 'O' && v.find(make_pair(newx, newy)) == v.end())
                    {
                        p.push(make_pair(newx, newy));
                        v.insert(make_pair(newx, newy));
                        vv[newx][newy] = true;
                    }
                } else
                    ok = false;
            }
        }
        
        if (ok)
        {
            for (auto &&pa: v)
            {
                g[pa.first][pa.second] = 'X';
            }
        }
    
    }
public:
    void solve(vector<vector<char>>& board) {
        vv.clear();
        if (!board.empty()) vv.resize(board.size(), vector<bool>(board[0].size()));
        
        for (int i=0; i<board.size(); ++i)
            for (int j=0; j<board[0].size(); ++j)
                if (board[i][j] == 'O' && !vv[i][j])
                    fill(i, j, board);
    }
};