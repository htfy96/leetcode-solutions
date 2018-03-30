class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        const int total = 1 << nums.size();
        vector<int> w;
        vector<vector<int>> ans;
        w.reserve(nums.size()); ans.reserve(total);
        for (int k=0; k<total; ++k) {
            for (int i=0; i<nums.size(); ++i)
                if ((1 << i) & k) {
                    w.push_back(nums[i]);
                }
                ans.push_back(w);
                w.clear();
        }
        return ans;
    }
};