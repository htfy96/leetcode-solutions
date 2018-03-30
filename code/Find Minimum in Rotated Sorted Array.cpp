class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r=nums.size() -1;
        const int n = nums.size();
        int ans = nums[0];
        while (r-l > 2)
        {
            cout << "l=" << l << " r=" << r << endl;
            int mid = (l+r) / 2;
            if (nums[mid] > nums[l])
            {
                ans = min(ans, nums[l]);
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        for (int i=l; i<=r; ++i)
            ans = min(ans, nums[i]);
        return ans;
    }
};