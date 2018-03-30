class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left_min = INT_MAX;
        vector<int> prebest;
        prebest.reserve(prices.size());
        for (int i=0; i<prices.size(); ++i) {
            left_min = min(left_min, prices[i]);
            prebest.push_back(max(prices[i] - left_min, i ? prebest[i-1] : 0));
        }
        int right_max = INT_MIN; int cur_best = 0; int ans = 0;
        for (int i=prices.size() - 1; i>=0; --i) {
            right_max = max(right_max, prices[i]);
            cur_best = max(cur_best, right_max - prices[i]);
            ans = max(ans, prebest[i] + cur_best);
        }
        return ans;
    }
};