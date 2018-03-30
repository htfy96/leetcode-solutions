
class Solution {
    vector<int> fa;
    
    int findfa(int x) {
        int w = x;
        while (fa[w] != w) w = fa[w];
        fa[x] = w;
        return w;
    }
    
    void merge(int x, int y)  {
        int f1 = findfa(x), f2 = findfa(y);
        fa[f1] = f2;
    }
public:
    int findCircleNum(vector<vector<int>>& M) {
        fa.clear();
        fa.reserve(M.size());
        for (int i=0; i<M.size(); ++i)
            fa.push_back(i);
        for (int i=0; i<M.size(); ++i)
            for (int j=0; j<M.size(); ++j)
                if (M[i][j]) merge(i, j);
        vector<bool> v(M.size());
        int ans = 0;
        for (int i=0; i<M.size(); ++i)
            if (!v[findfa(i)]) { ++ans; v[findfa(i)] = true; }
        return ans;
    }
};