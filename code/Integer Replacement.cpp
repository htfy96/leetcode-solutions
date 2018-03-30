class Solution {
public:
    struct Record
    {
        long n;
        long cnt;
    };
    int integerReplacement(long n) {
        cout << n << endl;
        if (n == 1)
            return 0;
        if (n == 3)
            return 2;
        if (n % 2 == 0)
            return integerReplacement(n/2) + 1;
        if (n % 4 == 1)
            return integerReplacement(n-1) + 1;
        else
            return integerReplacement(n+1) + 1;
    }
};