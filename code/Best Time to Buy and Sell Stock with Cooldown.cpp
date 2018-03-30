#pragma GCC optimize("-Ofast")
#pragma GCC optimize("-march=native")
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // f[i] = max(f[j-2] + prices[i] - prices[j]) | j <= i
        // g[i] = max(f[k-2] - prices[k]), k<=i = max(g[i-1], f[i-2] - prices[i])
        // f[i] = g[i] + prices[i]
        if (prices.empty()) return 0;
        int f[3], best_f[3] {INT_MIN, INT_MIN, INT_MIN};
        int g = INT_MIN;
        int ans = 0;
        for (int i=0; i<prices.size(); ++i) {
            g = max(g, (i>1 ? best_f[(i+1)%3] : 0) - prices[i]);
            f[i%3] = prices[i] + g;
            
            ans = max(ans, f[i%3]);
            best_f[i%3] = max(best_f[(i+2) % 3], f[i%3]);
        }
        return ans;
        
        
    }
};