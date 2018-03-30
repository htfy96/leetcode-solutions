class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        deque<int> d;
        long ans = LONG_MIN, sum = 0;
        for (int n:nums)
        {
            while (!d.empty() && sum < 0)
            {
                sum -= d.front();
                d.pop_front();
            }
            sum += n;
            d.push_back(n);
            ans = max(ans, sum);
        }
        return ans;
    }
};