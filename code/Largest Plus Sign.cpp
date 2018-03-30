#define printarr2(a, n) for (int _w=0; _w<n; ++_w) { for (int _p=0; _p<n; ++_p) cout << a[_w * n + _p] << " "; cout << endl; }
class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<bool> a(N * N, false);
        for (auto&& mine: mines) {
            a[mine[0] * N + mine[1]] = true;
        }
        vector<int> up(N*N, -1), down(N*N, N), left(N*N, -1), right(N*N, N);
        for (int i=0; i<N; ++i) {
            for (int j=0; j<N; ++j)
                left[i*N+j] = a[i*N+j] ? j : (j ? left[i*N+j-1]: -1);
            for (int j=N-1; j>=0; --j)
                right[i*N+j] = a[i*N+j] ? j : (j < N-1 ? right[i*N+j+1] : N);
        }
        for (int j=0; j<N; ++j) {
            for (int i=0; i<N; ++i)
                up[i*N+j] = a[i*N+j] ? i : (i ? up[(i-1) * N +j] : -1);
            for (int i=N-1; i>=0; --i)
                down[i*N+j] = a[i*N+j] ? i : (i < N-1 ? down[(i+1) * N + j] : N);
        }
        /*
        printarr2(left, N);
        printarr2(right, N);
        printarr2(up, N);
        printarr2(down, N);
        */
        
        int ans = 0;
        for (int i=0; i<N; ++i)
            for (int j=0; j<N; ++j)
                ans = max(ans, min(min(right[i*N+j] - j, j - left[i*N+j]), min(down[i*N+j] - i, i- up[i*N+j])));
        return ans;
            
    }
};