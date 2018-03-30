class Solution {
public:
    int numDecodings(string s) {
        if (s.empty()) return 0;
        int f[3];
        f[0] = 1;
        for (int i=1; i<=s.size(); ++i) {
            if (s[i-1] >= '1') f[i%3] = f[(i+2) % 3]; // = -1
            else f[i%3] = 0;
            if (i >= 2 && (s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6')))
                f[i%3] += f[(i+1) % 3];
        }
        return f[s.size() % 3];
    }
};