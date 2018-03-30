class Solution {
    using Grid = vector<vector<int>>;
    
    Grid *a;
    int d[120][120];
    bool v[120][120];
    
    bool valid(int x, int y)
    {
        return x >= 0 && y>=0 && x < a->size() && y < (*a)[0].size();
    }
    
    int getD(int x, int y)
    {
        return valid(x,y) ? d[x][y] : -1000000;
    }
    
    int getA(int x, int y)
    {
        return valid(x,y) ? (*a)[x][y] : -1000000;
    }
    
    void setD(int x, int y, int w)
    {
        valid(x, y) ? d[x][y] = w : 0;
    }
    
    
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        a = &heightMap;
        memset(d, 0x2f, sizeof(d));
        memset(v, 0, sizeof(v));
        queue<pair<int, int>> q;
        
        static const int dx[] = {0, 0, 1, -1}, dy[]= {1, -1, 0, 0};
        for (int i=0; i<(*a).size(); ++i)
            for (int j=0; j<(*a)[0].size(); ++j)
            {
                q.push(make_pair(i, j));
                v[i][j] = true;
            }
        
        while (!q.empty())
        {
            auto x = q.front(); q.pop();
            //cout << "Updating " << x.first << "," << x.second << endl;
            // updateSelf
            for (int i=0; i<4; ++i)
                setD(x.first, x.second, max(0, min(getD(x.first, x.second), 
                getD(x.first + dx[i], x.second + dy[i]) + getA(x.first + dx[i], x.second + dy[i]) - getA(x.first, x.second))));
            for (int i=0; i<4; ++i)
            {
                int dd = max(0, getD(x.first, x.second) + getA(x.first, x.second) - getA(x.first + dx[i], x.second + dy[i]));
                if (dd < getD(x.first + dx[i], x.second + dy[i]))
                {
                    setD(x.first + dx[i], x.second + dy[i], dd);
                    if (!v[x.first + dx[i]][x.second + dy[i]])
                    {
                        v[x.first + dx[i]][x.second + dy[i]] = true;
                        q.push(make_pair(x.first + dx[i], x.second + dy[i]));
                    }
                }
            }
            v[x.first][x.second] = false;
        }
        long long ans = 0;
        for (int i=0; i<a->size(); ++i) {
            for (int j=0;j<(*a)[0].size(); ++j) {
                //cout << d[i][j] << " ";
                ans += d[i][j];
            }
          //  cout << endl;
        }
        return ans;
    }
};