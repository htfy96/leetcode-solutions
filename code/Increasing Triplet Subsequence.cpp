class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min1 = INT_MAX, min2 = INT_MAX;
        for (int v: nums) {
            if (v > min2) return true;
            if (v > min1 && v < min2) min2 = v;
            else if (v < min1) min1 = v;
        }
        return false;
    }
};