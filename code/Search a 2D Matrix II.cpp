class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        if (matrix[0].empty()) return false;
        int idx = lower_bound(matrix[0].begin(), matrix[0].end(), target) - matrix[0].begin();
        for (int i=0; i<matrix.size(); ++i)
        {
            while (idx && matrix[i][idx-1] >= target) --idx;
            if (idx < matrix[0].size() && matrix[i][idx] == target) return true;
        }
        return false;
    }
};