class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int l = 0, r = nums.size();
        while (r-l > 1)
        {
            int mid = (r-l) / 2 + l;
            
            if (nums[mid] == target) return mid;
            if (nums[mid] >= nums[l]) // 4 5 6 7 8 1 2
            {
                if (target >= nums[l] && target < nums[mid]) r = mid; else l = mid + 1;
            }
            else  // 6 7 0 1 2 3 4
            {
                if (target >= nums[mid] && target <= nums[r-1]) l = mid; else r = mid;
            }
        }
        return nums[l] == target ? l : -1;
    }
};