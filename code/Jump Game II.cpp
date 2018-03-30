class Solution {
public:
    int jump(vector<int>& nums) {
        int stage = 0;
        int curStageLast = 0, nextStageLast = 0;
        for (int i=0; i<nums.size(); ++i)
        {
            if (i > curStageLast)
            {
                ++stage;
                curStageLast = nextStageLast;
            }
            nextStageLast = max(nextStageLast, i + nums[i]);
        }
        return stage;
    }
};