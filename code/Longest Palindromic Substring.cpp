#pragma GCC target ("arch=skylake-avx512")
#pragma GCC optimize ("-O3,-ffast-math")
class Solution {
public:
    string longestPalindrome(string s) {
        string ss;ss.reserve(s.size() * 2);
        if (s.empty()) return "";
        constexpr char kSep = '\126';
        for (int i=0; i<s.size(); ++i)
        {
            if (i) ss.push_back(kSep);
            ss.push_back(s[i]);
        }
        vector<int> f(ss.size());
        cout << ss << endl;
        f[0] = 1; int ed = 1, edi = 0; int ans = 1, ansi = 0;
        for (int i=1; i<ss.size(); ++i)
        {
            int reflected = 2 * edi - i; int already_match = 0;
            if (i < ed)
                already_match = min(f[reflected] / 2, ed - i - 1);
            if (i + already_match < ed - 1)
            {
                f[i] = already_match * 2 + 1;
                //cout << " i=" << i << " c=" << ss[i] << " f[i]=" << f[i] << endl;
                continue;
            }
            //cout << "already_match step1=" << already_match << endl;
            while (i - already_match - 1 >=0 && i + already_match + 1 < ss.size() && ss[i - already_match - 1] == ss[i + already_match + 1])
                ++already_match;
            //cout << "already_match step2=" << already_match << endl;
            if (i + already_match + 1 > ed)
            {
                ed = i + already_match + 1;
                edi = i;
            }
            int curlen = ss[i] == kSep ? (already_match + 1) / 2 * 2 : already_match / 2 * 2 + 1;
            if (curlen > ans)
            {
                ans = curlen;
                ansi = i;
            }
            f[i] = already_match * 2 + 1;
            //cout << " i=" << i << " c=" << ss[i] << " f[i]=" << f[i] << endl;
        }
        string anss; anss.reserve(f[ansi]);
        for (int i = ansi - f[ansi] / 2; i <= ansi + f[ansi] / 2; ++i)
            if (ss[i] != kSep)
                anss.push_back(ss[i]);
        return anss;
    }
};