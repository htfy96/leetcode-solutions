class Solution {
    struct Rec
    {
        int val, pos;
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<Rec> d;
        vector<int> ans;
        for (int i=0; i<nums.size(); ++i)
        {
            while (!d.empty() && d.front().pos <= i - k) d.pop_front();
            while (!d.empty() && d.back().val < nums[i]) d.pop_back();
            d.push_back(Rec {nums[i], i});
            if (i >= k-1)
                ans.push_back(d.front().val);
        }
        return ans;
    }
};