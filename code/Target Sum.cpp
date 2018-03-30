class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<int> v(2 * 2005);
        if (S > 1000 || S < -1000) return 0;
        #define idx(i, j) ((i+2) % 2 * 2005 + (j) + 1000)
        v[idx(-1, 0)] = 1;
        #define valid(x) ((x) >= -1000 && (x) <= 1000)
        for (int i=0; i<nums.size(); ++i)
            for (int j=-1000; j<=1000; ++j)
                v[idx(i, j)] = (valid(j-nums[i]) ? v[idx(i-1, j-nums[i])]: 0) + (valid(j+nums[i]) ? v[idx(i-1, j + nums[i])] : 0);
        return v[idx(nums.size() - 1, S)];
    }
};