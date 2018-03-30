class Solution {
public:
    static bool ok[2][800];
    bool canPartition(vector<int>& nums) {
        
        memset(ok[1], 0, sizeof(ok[1]));
        ok[1][400] = true;
        for (int i=0; i<nums.size(); ++i)
        {
            int cur = i & 1, prev = !cur;
            for (int j=0; j<800; ++j)
            {
                ok[cur][j] = false;
                if (j >= nums[i])
                    ok[cur][j] |= ok[prev][j-nums[i]];
                if (j + nums[i] < 800)
                    ok[cur][j] |= ok[prev][j+nums[i]];
            }
        }
        return ok[(nums.size() - 1) & 1][400];
    }
};

bool Solution::ok[2][800];