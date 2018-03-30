class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int f[102][102];
        memset(f, 0, sizeof(f));
        
        int ans = 0;
        for (int i=0; i<strs.size(); ++i)
        {
            string &s = strs[i];
            int zero = count(s.begin(), s.end(), '0'); int one = s.size() - zero;
            for (int x=m; x>=0; --x)
                for (int y=n; y>=0; --y)
                    if (x >= zero && y >= one)
                    {
                        f[x][y] = max(f[x][y], f[x-zero][y-one] + 1);
                        ans = max(ans, f[x][y]);
                    }
        }
        return ans;
    }
};