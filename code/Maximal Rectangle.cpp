class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        const int m = matrix.size(), n = matrix[0].size();
        vector<int> right1(m * n);
        #define idx(i, j) ((i) * n + (j))
        for (int i=0; i<m; ++i)
            for (int j=n-1; j>=0; --j)
            {
                right1[idx(i, j)] = matrix[i][j] == '1' ? (j == n-1 ? 1 : right1[idx(i, j + 1)] + 1) : 0;
            }
        vector<int> buf; buf.reserve(m);
        int ans = 0;
        for (int j=0; j<n; ++j)
        {
            buf.clear();
            for (int i=0; i<m; ++i)
                buf.push_back(right1[idx(i, j)]);
            buf.push_back(0);
            stack<int> s;
            s.push(-1);
            #define val(i) ((i) >= 0 ? buf[(i)] : 0)
            for (int i=0; i<buf.size(); ++i)
            {
                while (buf[i] < val(s.top()))
                {
                    int ni = s.top();
                    s.pop();
                    ans = max(ans, val(ni) * (i - s.top() - 1));
                }
                s.push(i);
            }
        }
        return ans;
    }
};