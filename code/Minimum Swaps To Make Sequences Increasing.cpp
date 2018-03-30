class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        vector<int> f((A.size() + 1) * 2, INT_MAX / 2);
        #define idx(x, y) ((x) * 2 + (y))
        f[idx(0, 0)] = 0;
        f[idx(0, 1)] = 1;
        for (int i=1; i<A.size(); ++i)
            for (int j=0; j<2; ++j)
            {
                int a_swapped = A[i], b_swapped = B[i];
                if (j) swap(a_swapped, b_swapped);
                if (a_swapped > A[i-1] && b_swapped > B[i-1]) f[idx(i, j)] = min(f[idx(i, j)], f[idx(i-1, 0)] + j);
                if (a_swapped > B[i-1] && b_swapped > A[i-1]) f[idx(i, j)] = min(f[idx(i, j)], f[idx(i-1, 1)] + j);
            }
        return min(f[idx(A.size() - 1, 0)], f[idx(A.size() - 1, 1)]);
    }
};