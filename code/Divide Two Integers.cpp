class Solution {
public:
    int divide(int dividend, int divisor) {
        bool sign = (dividend >= 0) ^ (divisor >=0); // sign = true: negative
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        if (dividend == INT_MIN && divisor == 1 ) return INT_MIN;
        long long dividendx = abs((long long)dividend), divisorx = abs((long long)divisor);
        int ans = 0;
        int high = 0;
        for (int i=0; i<31; ++i)
            if (divisorx & (1<<i))
                high = i;
     //   cout << "high = " << high << endl;
        
        for (long long i=30-high; i>=0; --i)
            while ((divisorx << i) <= dividendx)
            {
                ans += 1 << i;
                dividendx -= divisorx << i;
            //    cout << "i=" << i << " ans=" << ans << " divosor << i " << (divisorx << i) << "dividendx=" << dividendx << endl;
            }

        return (sign ? -1 : 1) * ans;
    }
};