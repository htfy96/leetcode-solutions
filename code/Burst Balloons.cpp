class Solution {
public:
    int maxCoins(vector<int>& nums) {
        if (nums.empty()) return 0;
        vector<int> a(nums.size() * nums.size());
        #define idx(i, j) ((i) * nums.size() + (j))
        #define val(idx) ((idx) >= 0 && (idx) < nums.size() ? nums[(idx)] : 1)
        for (int k=0; k<nums.size(); ++k)
            for (int i=0; i < nums.size() - k; ++i)
                for (int j=i; j<=i+k; ++j)
                {
                    int result = val(j) * val(i-1) * val(i+k+1);
                    if (j != i) result += a[idx(i, j-1)];
                    if (j != i+k) result += a[idx(j+1, i+k)];
                    a[idx(i, i+k)] = max(a[idx(i, i+k)], result);
                    //cout << "i=" << i << " k=" << k << " i+k=" << i+k << " j=" << j << " a=" << a[idx(i, i+k)] << endl;
                }
        return a[idx(0, nums.size() - 1)];
    }
};