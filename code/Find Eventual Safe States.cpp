class Solution {
    vector<int> v; vector<bool> unsafe;
    void dfs(const vector<vector<int>>& graph, int x)
    {
        v[x] = 1;
        //cout << "visiting " << x << endl;
        for (int y: graph[x])
        {
            //cout << " iterating y=" << y << endl;
            if (!v[y])
                dfs(graph, y);
            unsafe[x] = unsafe[x] || unsafe[y];
            if (v[y] == 1) unsafe[x] = true;
        }
        //cout << "exiting " << x << endl;
        v[x] = 2;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        v.clear(); v.resize(graph.size());
        unsafe.clear(); unsafe.resize(graph.size());
        vector<int> ans;
        for (int i=0; i<graph.size(); ++i)
        {
            if (!v[i])
                dfs(graph, i);
            if (!unsafe[i])
                ans.push_back(i);
        }
        return ans;
    }
};