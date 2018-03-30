class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int ans = 0;
        int last_invalid = -1, last_valid = -1;
        for (int i=0; i<A.size(); ++i)
        {
            if (A[i] > R) last_invalid = i;
            if (A[i] >= L) last_valid = i;
            ans += max(last_valid - last_invalid, 0);
        }
        return ans;
    }
};