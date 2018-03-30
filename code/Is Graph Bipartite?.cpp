class Solution {
    unordered_map<int, bool> m;
    void dfs(int x, vector<vector<int>>& v)
    {
        for (int t: v[x])
            if (m.find(t) != m.end()) {
                if (m[t] == m[x])
                    throw runtime_error("failed");
            } else {
                m[t] = !m[x];
                dfs(t, v);
            }
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        try {
        for (int i=0; i<graph.size(); ++i)
            if (m.find(i) == m.end()) {
                m[i] = false;
                dfs(i, graph);
            }
        } catch (runtime_error& e) {
            return false;
        }
        return true;
    }
};