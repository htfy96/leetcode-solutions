class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> v(n);
        if (edges.empty()) return vector<int> {0};
        for (auto &&p: edges)
        {
            v[p.first].push_back(p.second);
            v[p.second].push_back(p.first);
        }
        vector<int> q;
        for (int i=0; i<n; ++i)
        {
                sort(v[i].begin(), v[i].end());
                if (v[i].size() == 1)
                q.push_back(i);
        }
        while (n > 2)
        {
            n-=q.size();
            vector<int> qq;
            for (int x: q) {
            int other = v[x][0]; v[x].clear();
            auto newIt = remove(v[other].begin(), v[other].end(), x);
            v[other].erase(newIt, v[other].end());
            if (v[other].size() == 1)
                qq.push_back(other);
            }
            q = qq;
        }
        return q;
    }
};