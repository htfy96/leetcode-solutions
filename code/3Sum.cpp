class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        //for (int v: nums) cout << v << " "; cout << endl;
        for (int i=0; i<nums.size(); ++i)
        {
            if (i && nums[i] == nums[i-1]) continue;
            int k;
            for (int j=i+1; j<nums.size(); ++j) {
                if (nums[j] == nums[j-1] && j-1 != i) continue;
                if (j == i+1) {
                    k = upper_bound(nums.begin(), nums.end(), -nums[i] - nums[j]) - nums.begin();
                    --k;
                }
                //cout << i << " " << j << " " << k << endl;
                while (k > j && nums[i] + nums[j] + nums[k] > 0) --k;
                //cout << i << " " << j << " " << k << endl;
                //while (k-1 > j && nums[k] == nums[k+1]) --k;
                //cout << i << " " << j << " " << k << endl;
                if (k<=j) break;
                if (nums[k] + nums[i] + nums[j] == 0) ans.push_back({nums[i], nums[j], nums[k]});
            }
        }
        return ans;
    }
};