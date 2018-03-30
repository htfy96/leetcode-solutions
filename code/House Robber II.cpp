class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];
        if (nums.empty())
            return 0;
        vector<int> f; int ans = -1000000;
        // don't choose zero
        f.clear(); f.resize(nums.size());
        f[1] = nums[1];
        for (int i=2; i<nums.size(); ++i)
        {
            f[i] = max(nums[i] + f[i-2], f[i-1]);
            cout << "i=" << i << " f=" << f[i] << endl;
        }
        ans = f[nums.size() - 1];
        
        cout << "==== choose 0 " << endl;
        
        // choose 0
        f.clear(); f.resize(nums.size());
        f[0] = nums[0];
        f[1] = f[0];
        for (int i=2; i<nums.size() - 1; ++i)
            f[i] = max(nums[i] + f[i-2], f[i-1]);
        ans = max(ans, f[nums.size() - 2]);
        return ans;
            
    }
};