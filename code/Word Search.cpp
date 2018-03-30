class Solution {
    bool search(vector<pair<int, int>> &pos, const string &word, const vector<vector<char>> &board)
    {
        auto cur = *pos.rbegin();
     //   cout << "Searching at pos=" << cur.first << "," << cur.second << endl;

        if (pos.size() == word.size()) return true;
        static const int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
        for (int i=0; i<4; ++i)
        {
            int x = cur.first + dx[i], y = cur.second + dy[i];
            if (x >= 0 && x < board.size() && y>=0 && y < board[0].size() && board[x][y] == word[pos.size()] && find(pos.begin(), pos.end(), make_pair(x, y)) == pos.end())
            {
                pos.push_back(make_pair(x, y));
                if (search(pos, word, board)) return true;
                pos.pop_back();
            }
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<pair<int, int>> pos;
        for (int i=0; i<board.size(); ++i)
            for (int j=0; j<board[0].size(); ++j)
                if (board[i][j] == word[0])
                {
                    pos.push_back(make_pair(i, j));
                    if (search(pos, word, board)) return true;
                    pos.pop_back();
                }
        return false;
    }
};