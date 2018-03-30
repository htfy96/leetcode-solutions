#pragma GCC optimize("-march=native")
#pragma GCC optimize("-fipa-pta")

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.empty()) return {vector<int>{}};
        vector<vector<int>> ans;
        int power = 1;
        for (int i=1; i<=nums.size(); ++i) power *= i;
        vector<bool> b;
        for (int i=0; i<power; ++i) {
            int w = i;
            b.clear(); b.resize(nums.size(), true);
            //cout << "i = " << i << endl;
            vector<int> result; result.reserve(nums.size());
            for (int j=nums.size(); j>0; --j) {
                int idx = (w % j + 1);
                w /= j;
                for (int k = 0; k<= b.size(); ++k) {
                    if (b[k] && !(--idx)) {
                        b[k] = false;
                        result.push_back(nums[k]);
                    }
                }
            }
            ans.push_back(result);
        }
        return ans;
    }
};