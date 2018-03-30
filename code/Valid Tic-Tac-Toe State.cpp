class Solution {
    static constexpr int dx[] = {1, 0, 1, -1}, dy[] = {0, 1, 1, 1};
    static bool valid(int x, int y) {
        return x >= 0 && x < 3 && y >=0 && y <3;
    }
    static int count(const vector<string>& board, char op) {
        int ans = 0;
        for (int i=0; i<3; ++i)
            for (int j=0; j<3; ++j)
                ans += board[i][j] == op;
        return ans;
    }
    static bool check_win(const vector<string>& board, char op) {
        for (int i=0; i<3; ++i)
            for (int j=0; j<3; ++j)
                for (int k=0; k<4; ++k) {
                    bool ok = true;
                    for (int h = 0; h<3; ++h)
                        if (!valid(i + dx[k] * h, j + dy[k] * h) || board[i + dx[k] * h][j + dy[k] * h] != op) {
                            ok = false;
                            break;
                        }
                    if (ok) return true;
                }
        return false;
    }
public:
    bool validTicTacToe(vector<string>& board) {
        int x_cnt = count(board, 'X'), o_cnt = count(board, 'O');
        bool x_win = check_win(board, 'X'), o_win = check_win(board, 'O');
        //cout << x_cnt << " o=" << o_cnt << " x_win=" << x_win << " o_win=" << o_win << endl;
        return (x_cnt - o_cnt == 0 && !x_win) || (x_cnt - o_cnt == 1 && !o_win);
        
    }
};
constexpr int Solution::dx[], Solution::dy[];