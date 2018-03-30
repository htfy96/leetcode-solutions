class Solution {
    static const int MAGIC = 0x8000;
    bool getVal(int x)
    {
        return x & Solution::MAGIC ? !(x&1) : (x&1);
    }
    
    void setVal(int &x, bool newval)
    {
        if (newval != getVal(x))
        {
            x = newval;
            x |= Solution::MAGIC;
        }
    }
    
    int m, n;
    vector<vector<int>> *b;
    
    bool getState(int x, int y)
    {
        if (x<0 || x >= m || y<0 || y >=n)
            return false;
        else
            return getVal((*b)[x][y]);
    }
    
    int getAdjCnt(int x, int y)
    {
        static const int dx[] = {-1, 1, 0, 0, 1, 1, -1, -1},
            dy[] = {0, 0, 1, -1, -1, 1, -1, 1};
        int ans = 0;
        for(int i=0; i<8; ++i)
            ans += getState(x+dx[i], y+dy[i]);
        return ans;
        
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        b = &board;
        m = board.size(); n = board.empty() ? 0 : board[0].size();
        for (int i=0; i<board.size(); ++i)
            for (int j=0; j<board[0].size(); ++j)
            {
                int adj = getAdjCnt(i, j);
                bool cur = getState(i, j);
                cout << i << "," << j << ": adj=" << adj << " cur=" << cur << endl;
                if (cur)
                {
                    if (adj < 2 || adj >= 4)
                        setVal(board[i][j], false);
                }
                else
                    if (adj == 3)
                        setVal(board[i][j], true);
            }
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
                board[i][j] &= 0x1;
    }
};