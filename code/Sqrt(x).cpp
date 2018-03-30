class Solution {
public:
    int mySqrt(int x) {
        if (x < 0)
            throw runtime_error("Invalid input");
        int left = 0;
        int right = INT_MAX;
        while (left < right - 1)
        {
            long long mid = ((long long)left + right) / 2;
            long long squared = mid * mid;
            if (squared == x)
                return mid;
            else if (squared < x)
            {
                left = mid;
            } else
            {
                right = mid - 1;
            }
        }
        for (int i=right; i>=left; --i)
            if ((long long) i * i <= x)
                return i;
    }
};