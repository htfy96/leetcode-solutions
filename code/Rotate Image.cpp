class Solution {
    struct Coord
    {
        int x, y;
    };
    
    int n;
    
    inline Coord ror90(Coord coord) {
        float x_rela = (float)coord.x - (n-1)/2.0f, y_rela = (float)coord.y - (n-1)/2.0f;
        float new_x_rela = -y_rela, new_y_rela = x_rela;
        auto ans = Coord { round(new_x_rela + (n-1)/2.0f), round(new_y_rela + (n-1) / 2.0f) };
        //cout << "before: " << coord.x <<"," << coord.y <<" after:" << ans.x << "," << ans.y << endl;
        return ans;
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        n = matrix.size();
        vector<int> tmp; tmp.reserve(n);
        for (int lvl = 0; lvl < n / 2; ++lvl)
        {
            Coord coord;
            tmp.clear(); coord.y = n-1-lvl;
            for (coord.x = lvl + 1; coord.x < n - lvl; ++coord.x)
                tmp.push_back(matrix[coord.x][coord.y]);
            #define rotate() matrix[coord.x][coord.y] = matrix[ror90(coord).x][ror90(coord).y]
            cout << "prepare finish" << endl;
            for (coord.x = lvl + 1; coord.x < n-lvl; ++coord.x)
                rotate();
            cout << "rotate 1 finish" << endl;
            coord.x = lvl;
            for (coord.y = lvl + 1; coord.y < n-lvl; ++coord.y)
                rotate();
            cout << "rotate 2 finish" << endl;

            coord.y = lvl;
            for (coord.x = lvl; coord.x < n - lvl - 1; ++coord.x)
                rotate();
            cout << "rotate 3 finish" << endl;

            coord.x = n - 1 - lvl;
            int cnt = tmp.size() - 1;
            for (coord.y = lvl; coord.y < n- lvl - 1; ++coord.y)
                matrix[coord.x][coord.y] = tmp[cnt--];
            #undef rotate
        }
    
    }
};