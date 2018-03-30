class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int first_0 = 0, first_minus = -1, product_since_after_0 = INT_MIN, product_since_minus = INT_MIN;
        int minus_cnt = 0;
        for (int i=0; i<nums.size(); ++i)
        {
            int x = nums[i];
            if (!x)
            {
                first_0 = i;
                first_minus = -1;
                product_since_after_0 = INT_MIN;
                product_since_minus = INT_MIN;
                minus_cnt = 0;
                ans = max(ans, 0);
            } else if (x > 0)
            {
                if (product_since_after_0 == INT_MIN) product_since_after_0 = x;
                else product_since_after_0 *= x;
                if (product_since_minus != INT_MIN) product_since_minus *= x;
                ans = max(ans, product_since_minus);
                ans = max(ans, product_since_after_0);
            } else {
                if (first_minus == -1)
                {
                    first_minus = i;
                    product_since_minus = 1;
                }
                else
                {
                    product_since_minus *= x;
                    ans = max(ans, product_since_minus);
                }
                ++minus_cnt;
                if (product_since_after_0 == INT_MIN) product_since_after_0 = x;
                else product_since_after_0 *= x;
                ans = max(ans, x);
                ans = max(ans, product_since_after_0);
            }
           // cout << "after i=" << i << " first_0=" << first_0 << " firsT_minus=" << first_minus << " product_since_after_0=" << product_since_after_0 <<
           //     " product_since_minus=" << product_since_minus << " minus_cnt=" << minus_cnt << endl;
        }
        return ans;
        
    }
};