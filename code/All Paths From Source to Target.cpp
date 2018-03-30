class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        queue<vector<int>> q;
        q.push({0});
        vector<vector<int>> ans;
        while (!q.empty()) {
            vector<int> x = q.front();
            q.pop();
            int idx = *x.rbegin();
            if (idx + 1 == graph.size())
                ans.push_back(move(x));
            else
            for (int i=0; i<graph[idx].size(); ++i) {
                int t = graph[idx][i];
                vector<int> newx = x;
                newx.push_back(move(t));
                q.push(move(newx));
            }
        }
        return ans;
    }
};