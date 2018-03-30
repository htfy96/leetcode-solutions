class Solution {
    int get_global(int l, int r, vector<int>& a) {
        if (r-l <= 1) return 0;
        if (r-l == 2) { if (a[l] > a[l+1]) { swap(a[l], a[l+1]); return 1; } else return 0; }
        int mid = (l+r) / 2;
        static vector<int> buf;
        buf.reserve(r-l);
        int lcnt = get_global(l, mid, a),
            rcnt = get_global(mid, r, a);
        int mcnt = 0;
        //for (int v: a) cout << v << " "; cout << endl;
        int i=l, j = mid;
        while (i < mid) {
            while (j < r && a[i] > a[j]) {  buf.push_back(a[j]); ++j; }
            mcnt += j-mid;
            buf.push_back(a[i]); ++i;
        }
        for (; j<r; ++j) buf.push_back(a[j]);
        //cout << "sorted buf " << l << " " << r << endl;
        //for (int v: buf) cout << v << " "; cout << endl;
        copy(buf.begin(), buf.end(), a.begin() + l);
        buf.clear();
        return lcnt + rcnt + mcnt;
        
    }
public:
    bool isIdealPermutation(vector<int>& A) {
        int local = 0;
        for (int i=0; i<A.size() - 1; ++i)
            local += A[i] > A[i+1];
        int global = get_global(0, A.size(),  A);
        cout << "local="<< local << " global=" << global << endl;
        return local == global;
    }
};