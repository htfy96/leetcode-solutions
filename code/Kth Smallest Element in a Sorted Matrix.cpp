class Solution {
    int count_smaller_eq(const vector<vector<int>> & matrix, int k)
    {
        int ans = 0;
        int start_idx = upper_bound(matrix[0].cbegin(), matrix[0].cend(), k) - matrix[0].begin();
        for (int i=0; i<matrix.size(); ++i)
        {
            while (start_idx > 0 && matrix[i][start_idx - 1] > k) --start_idx;
            ans += start_idx;
        }
        return ans;
    }
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        double l = INT_MIN, r = INT_MAX;
        while (r-l > 0.05)
        {
            double mid = (l+r) / 2;
            int cnt_smaller = count_smaller_eq(matrix, mid);
            if (cnt_smaller < k) l = mid; else r = mid;
        }
        return round((l+r) / 2) + 0.01;
    }
};