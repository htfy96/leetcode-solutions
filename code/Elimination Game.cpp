class Solution {
    int calc(int n, int method)
    {
        if (n == 1)
            return 1;
        if (method == 1)
            return n % 2 == 0 ? 2 * calc(n/2, 2) - 1 : 2 *calc(n/2, 2);
        else
            return 2 * calc(n/2, 1);
    }
public:
    int lastRemaining(int n) {
        return calc(n, 2);
    }
};