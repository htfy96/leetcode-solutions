class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        static constexpr int kMagic = 19260711;
        if (matrix.empty()) return;
        int m = matrix.size(), n = matrix[0].size();
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j) {
                if (!matrix[i][j]) {
                    for (int k=0; k<n; ++k)
                        if (matrix[i][k]) matrix[i][k] = kMagic;
                    break;
                }
            }
        for (int j=0; j<n; ++j)
            for (int i=0; i<m; ++i)
                if (!matrix[i][j]) {
                    for (int k=0; k<m; ++k)
                        if (matrix[k][j]) matrix[k][j] = kMagic;
                    break;
                }
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
                if (matrix[i][j] == kMagic) matrix[i][j] = 0;
    }
};