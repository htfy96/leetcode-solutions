class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> left_max(height.size()), right_max(height.size());
        for (int i=1; i<height.size(); ++i)
            left_max[i] = max(height[i-1], left_max[i-1]);
        for (int i=height.size() - 2; i>=0; --i)
            right_max[i] = max(height[i+1], right_max[i+1]);
        long long ans = 0;
        for (int i=0; i<height.size(); ++i)
            ans += max(0, min(left_max[i], right_max[i]) - height[i]);
        return ans;
    }
};