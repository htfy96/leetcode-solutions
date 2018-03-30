class Solution {
    static int count_smaller(double x, const vector<int>& A) {
        int ans = 0;
        for (int i=0; i<A.size(); ++i)
            ans += lower_bound(A.begin(), A.begin() + i, x * A[i]) - A.begin();
        return ans;
    }
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& A, int K) {
        double l = 0.0, r = 1.0;
        while (r-l > 1e-14) {
            //cout << "l=" << l << " r=" << r << endl;
            double mid = (l+r) / 2, result = count_smaller(mid, A);
            if (result < K) l = mid; else r = mid;
        }
        for (int v: A)
            if (fabs(round(r * v) - r * v) < 1e-5)
                return {r * v + 0.9999, v};
    }
};