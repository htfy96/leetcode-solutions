class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        auto start = lower_bound(nums.cbegin(), nums.cend(), target);
        if (start == nums.end() || *start != target)
            return vector<int> {-1, -1};
        auto ed = upper_bound(nums.cbegin(), nums.cend(), target);
        return vector<int> { start - nums.cbegin(), ed - nums.cbegin() - 1};
    }
};