class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        #define idx(x, y) ((x) * (query_row + 1) + (y))
        vector<double> a((query_row + 2) * (query_row + 2));
        a[idx(0, 0)] = poured;
        for (int i=0; i<=query_row; ++i)
            for (int j=0; j<=i; ++j) {
                double overflow = max(a[idx(i, j)] - 1, 0.0);
                a[idx(i+1, j)] += overflow / 2.0;
                a[idx(i+1, j+1)] += overflow / 2.0;
                a[idx(i, j)] -= overflow;
                //cout << "i=" << i << " j=" << j << " a=" << a[idx(i, j)] << endl;
            }
        return a[idx(query_row, query_glass)];
    }
};