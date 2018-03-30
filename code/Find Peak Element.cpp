class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        #define GET(x) ((x<0 || x>=nums.size()) ? LONG_MIN : nums[x])
        for (int i=0; i<nums.size(); ++i)
            if (nums[i] > GET(i-1) && nums[i] > GET(i+1))
                return i;
        
    }
};