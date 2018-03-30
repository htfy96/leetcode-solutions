class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        if (matrix.empty()) return 0;
        vector<int> f[2] { vector<int>(matrix[0].size()), vector<int>(matrix[0].size()) };
        for (int i=0; i < matrix.size(); ++i)
            for (int j=0; j< matrix[0].size(); ++j)
                if (matrix[i][j] == '1')
                {
                    int m = j == 0 ? 0 : min(f[i % 2][j-1], min(f[(i+1) % 2][j], f[(i+1) % 2][j-1]));
                    f[i%2][j] = m + 1;
                    ans = max(ans, f[i%2][j]);
                }
                else
                f[i%2][j] = 0;
        return ans * ans;
                    
    }
};