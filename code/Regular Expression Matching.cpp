class Solution {
    struct SinglePattern
    {
        char c; // . stands for any
        bool multi; // false: occur once; true: occur 0 - inftimes
    };
public:
    bool isMatch(string s, string p) {
        vector<SinglePattern> patterns;
        for (int i=0; i<p.size();) {
            if (i + 1 >= p.size() || p[i+1] != '*') {
                patterns.push_back({p[i], false});
                i+=1;
            } else {
                patterns.push_back({p[i], true});
                i+=2;
            }
        }
        vector<bool> f((s.size() + 1) * (patterns.size() + 1));
        const int n = patterns.size() + 1;
        f[0] = true;
        for (int i=0; i<=s.size(); ++i)
            for (int j=0; j<n; ++j) {
                //cout << "calc: i=" << i << " j=" << j << endl;
                if (!j) continue;
                if (i+j==0) continue;
                SinglePattern sp = patterns[j-1];
                if (sp.multi) {
                    f[i*n+j] = f[i*n+j-1];
                    for (int k=1; k<=i; ++k) {
                        if (sp.c != '.' && s[i-k] != sp.c) break;
                        f[i*n+j] = f[i*n+j] || f[(i-k) * n + j-1];
                    }
                } else
                    f[i*n+j] = !i ? false : (sp.c == '.' || s[i-1] == sp.c) && f[(i-1)*n + j-1];
                //cout << "f[" << i << "," << j << "]=" << f[i*n+j] << endl;
                
            }
        return f[s.size() * n + patterns.size()];
    }
};