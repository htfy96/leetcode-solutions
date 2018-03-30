class Solution {
public:
    double myPow(double x, long long n) {
        if (n == 0)
            return 1.0;
        if (n < 0) return 1.0 / myPow(x, -n);
        else
        {
            double y = myPow(x, n / 2);
            return n % 2 ? x * y * y : y * y;
        }
    }
};