class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> income(numCourses);
        vector<vector<int>> out(numCourses);
        for (auto&& p: prerequisites) {
            ++income[p.first];
            out[p.second].push_back(p.first);
        }
        queue<int> q;
        int cnt = 0;
        for (int i=0; i<numCourses; ++i)
            if (!income[i]) q.push(i);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            ++cnt;
            for (int w: out[x]) {
                if (--income[w] == 0) {
                    q.push(w);
                }
            }
        }
        return cnt == numCourses;
    }
};