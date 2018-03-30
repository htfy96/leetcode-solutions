class Solution {
public:
    // Max_j{ min(A_j, A_i) * (i-j) }
    int maxArea(vector<int>& height) {
        
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while (l < r)
        {
            ans = max(ans, min(height[l], height[r]) * (r-l));
            if (height[l] < height[r])
                ++l;
            else --r;
        }
        return ans;
    }
};