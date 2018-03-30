class Solution {
    static const int MOD = 1337;
    void div2(vector<int> &b)
    {
        int jw = 0;
        for (int i=b.size() -1; i>=0; --i)
        {
            int division = jw * 10 + b[i];
            jw = division % 2;
            b[i] = division / 2;
        }
        while (b.size() > 1 && *b.rbegin() == 0)
            b.pop_back();
    }
    int calc(int a, vector<int> &b)
    {
        a %= MOD;
        if (b.size() == 1 && b[0] == 0)
            return 1;
        bool odd = b[0] % 2;
        
        div2(b);
        int res = calc(a, b);
        int res2 = res * res % MOD;
        
        int res3 = odd ? (a * res2 ) % MOD : res2;
        return res3;
        
    }
public:
    int superPow(int a, vector<int>& b) {
        reverse(b.begin(), b.end());
        return calc(a, b);
    }
};