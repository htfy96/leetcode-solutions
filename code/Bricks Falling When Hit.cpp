class Solution {
    vector<int> fa;
    vector<int> cnt;
    void init_fa()
    {
        for (int i=0; i<fa.size(); ++i)
            fa[i] = i;
        cnt.clear();
        cnt.resize(fa.size(), 1);
    }
    
    int getfa(int x)
    {
        int w = x;
        while (w != fa[w]) w = fa[w];
        fa[x] = w;
        return w;
    }
    
    void merge(int x, int y)
    {
        int fa1 = getfa(x), fa2 = getfa(y);
        if (fa1 == fa2) return;
        fa[fa1] = fa2;
        cnt[fa2] += cnt[fa1];
    }
    
    void dumpfa()
    {
        /*
        cout << "fa: ";
        for (int v: fa) cout << getfa(v) << " ";
        cout << "\t cnt: ";
        for (int v: cnt) cout << v << " ";
        cout << endl;
        */
    }
    
    struct AdjGroup
    {
        int old_fa;
        int cnt;
    };
public:
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        if (grid.empty() || hits.empty()) return {};
        const int m = grid.size(), n = grid[0].size();
        #define idx(x, y) ((x) * n + (y))
        #define valid(x, y) ((x) >= 0 && (x) < m && (y) >= 0 && (y) < n)
        const int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
        fa.resize(m * n + 1);
        const int superblock = m * n;
        init_fa();
        vector<int> hit_bricks(m * n);
        reverse(hits.begin(), hits.end());
        for (int i=0; i<hits.size(); ++i)
            hit_bricks[idx(hits[i][0], hits[i][1])] = i + 1; // hit time. start from 1
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
                if (grid[i][j] && !hit_bricks[idx(i, j)])
                {
                    if (!i) merge(idx(i, j), superblock);
                    for (int k=0; k<4; ++k)
                    {
                        int nx = i + dx[k], ny = j + dy[k];
                        if (valid(nx, ny) && grid[nx][ny] && !hit_bricks[idx(nx, ny)])
                            merge(idx(i, j), idx(nx, ny));
                    }
                }
        //cout << "before stick..." << endl;
        dumpfa();
        vector<int> ans;
        for (int step=0; step < hits.size(); ++step)
        {
            int res = 0; int hitx = hits[step][0], hity = hits[step][1];
            if (!grid[hitx][hity])
                goto CNT_FINISH;
            {
            if (!hitx)
                merge(idx(hitx, hity), superblock);
            dumpfa();
            vector<AdjGroup> adj_group;
            #define for_all_valid_adj(codeblk) \
            for (int k=0; k<4; ++k) \
            { \
                int nx = hitx + dx[k], ny = hity + dy[k]; \
                if (valid(nx, ny) && grid[nx][ny] && hit_bricks[idx(nx, ny)] < step + 1) \
                    codeblk \
            }
            for_all_valid_adj({
                if (getfa(idx(nx, ny)) != getfa(superblock))
                    if (find_if(adj_group.cbegin(), adj_group.cend(), [&](const AdjGroup& g) { return g.old_fa == getfa(idx(nx, ny)); }) == adj_group.cend())
                        adj_group.push_back(AdjGroup { getfa(idx(nx, ny)), cnt[getfa(idx(nx, ny))]});
            })
            dumpfa();
            for_all_valid_adj({
                //cout << "merging [" << nx << "," << ny << "] and [" << hitx << "," << hity << "]" << endl;
                
                merge(idx(nx, ny), idx(hitx, hity));
                dumpfa();
            })
            
            for (auto&& adjg: adj_group)
                if (getfa(adjg.old_fa) == getfa(superblock))
                    res += adjg.cnt;
            //cout << "after merge of step=" << step << " res=" << res << endl;;
            dumpfa();
            }
                
            CNT_FINISH:
                ans.push_back(res);
            
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }               
};