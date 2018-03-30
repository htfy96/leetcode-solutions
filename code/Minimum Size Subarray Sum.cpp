class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if (nums.empty()) return 0;
        int sum = 0; int r = 0; int ans = 1000000000;
        for (int i=0; i<nums.size(); ++i)
        {
            if (r <= i) sum += nums[i]; r = max(r, i+1);
            cout << "i=" << i << " r=" << r << endl;
            while (r < nums.size() && sum < s)
            {
                sum += nums[r++];
            }
            if (sum >= s) ans = min(ans, r-i);
             cout << "i=" << i << " r=" << r << endl;
            sum -= nums[i];
        }
        return ans > 100000000 ? 0 : ans;
    }
};