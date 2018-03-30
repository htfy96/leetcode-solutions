class Solution {
public:
    int minMoves(vector<int>& nums) {
        long long minEle = *min_element(nums.begin(), nums.end());
        long long sum = accumulate(nums.begin(), nums.end(), 0);
        return sum - minEle * nums.size();
    }
};