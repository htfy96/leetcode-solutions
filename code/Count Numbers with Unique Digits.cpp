class Solution {
public:
    long long f[2][1024];
    int countNumbersWithUniqueDigits(int n) {
        memset(f, 0, sizeof(f));
        f[0][0] = 1;
        long long ans = 0;
        for (int i=1; i<=n ;++i)
        {
            for (int state = 0; state < 1024; ++state)
            {
                f[i % 2][state] = 0;
                for (int digit = 0; digit <= 9; ++digit)
                    if (state & (1 << digit))
                    {
                        f[i%2][state] += f[(i+1) %2][state ^ (1 << digit)];
                    }
                
            }
            
            for (int state = 0; state < 1024; ++state)
                for (int thisdigit = 1; thisdigit <= 9; ++thisdigit)
                    if (!(state & (1 << thisdigit)))
                    {
                       // if (f[(i+1)%2][state]) cout << "Added: state = " << state <<" thisdigit=" << thisdigit << endl;
                        ans += f[(i+1) %2][state];
                    }
        //    cout << "ans=" << ans << endl;
            
        }
       // long long ans = 0;
        //for (int state = 0; state < 1024; ++state)
        //    ans += f[n%2][state];
        // if n = 3
        // 000 001 002 003 004 005 ... 009
        // if n = 4
        // 0001
        return ans + 1;
    }
};