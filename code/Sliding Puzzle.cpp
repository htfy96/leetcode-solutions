class Solution {
    template<typename T>
    int b2s(const T & b) {
       int ans = 0;
       for (int i=0; i<2; ++i)
           for (int j=0; j<3; ++j)
               ans = ans * 6 + b[i][j];
        return ans;
    }
    array<array<int, 3>, 2> s2b(int x) {
        array<array<int, 3>, 2> result;
        int b = 1;
        for (int i=1; i>=0; --i)
            for (int j=2; j>=0; --j) {
                result[i][j] = (x / b) % 6;
                b *= 6;
            }
        return result;
    }
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        bool v[50000] {};
        queue<pair<int, int>> q;
        q.push(make_pair(b2s(board), 0));
        v[b2s(board)] = true;
        while (!q.empty()) {
            auto x = q.front();
            q.pop();
            if (x.first == 11190) return x.second;
            auto state = s2b(x.first);
            int step = x.second;
            static constexpr int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
            #define valid(x, y) (x >= 0 && y>=0 && x < 2 && y < 3)
            for (int i=0; i<2; ++i)
                for (int j=0; j<3; ++j) {
                    //cout << "i=" << i << " j=" << j << " = " << state[i][j] << endl;
                    if (!state[i][j])
                        for (int k=0; k<4; ++k)
                        {
                            int newx = i + dx[k], newy = j + dy[k];
                            if (valid(newx, newy)) {
                                auto newstate = state;
                                swap(newstate[i][j], newstate[newx][newy]);
                                int newv = b2s(newstate);
                                if (!v[newv])
                                {
                                    v[newv] = true;
                                    q.push(make_pair(newv, step + 1));
                                }
                            }
                        }
                }
        }
        return -1;
    }
};