class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        array<bool, 10> vrow, vcol, vcell;
        static constexpr int cell_startx[] = {0, 0, 0, 3, 3, 3, 6, 6, 6},
        cell_starty[] = {0, 3, 6, 0, 3, 6, 0, 3, 6},
        cell_offx[] = {0, 0, 0, 1, 1, 1, 2, 2, 2},
        cell_offy[] = {0, 1, 2, 0, 1, 2, 0, 1, 2};
        for (int i=0; i<9; ++i)
        {
            fill(vrow.begin(), vrow.end(), false);
            fill(vcol.begin(), vcol.end(), false);
            fill(vcell.begin(), vcell.end(), false);
            for (int j=0; j<9; ++j){
                if (board[i][j] == '.') goto CHECK_COL;
                if (vrow[board[i][j] - '0']) { 
                    //cout << "row failed at " << i << " " << j << endl;
                    return false; }
                vrow[board[i][j] - '0'] = true;
                CHECK_COL:
                if (board[j][i] == '.') goto CHECK_CELL;
                if (vcol[board[j][i] - '0']) { 
                    //cout << "col failed at " << j << " " << i << endl; 
                    return false; }
                vcol[board[j][i] - '0'] = true;
                CHECK_CELL:
                int cellx = cell_startx[i] + cell_offx[j],
                    celly = cell_starty[i] + cell_offy[j];
                if (board[cellx][celly] == '.') goto CHECK_END;
                if (vcell[board[cellx][celly] - '0']) { 
                    //cout << "col failed at " << cellx << " " << celly << endl;
                    return false; }
                vcell[board[cellx][celly] - '0'] = true;
                CHECK_END:
                continue;
            }
        }
        return true;
    }
};