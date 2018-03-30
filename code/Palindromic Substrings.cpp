class Solution {
public:
    int countSubstrings(string s) {
        if (s.empty()) return 0;
        string ss; ss.reserve(s.size() * 2);
        constexpr char kSep = '\127';
        for (int i=0; i<s.size(); ++i)
        {
            if (i) ss.push_back(kSep);
            ss.push_back(s[i]);
        }
        int ed = 1, edi = 0;
        vector<int> f(ss.size());
        cout << ss << endl;
        f[0] = 1;
        long long ans = 1;
        for (int i=1; i<ss.size(); ++i)
        {
            int reflected = 2 * edi - i;
            int already_match = 1;
            if (i < ed)
                already_match =  min(ed - i, f[reflected]);
            if (already_match + i < ed)
                goto FINISH;
            while (i - already_match >= 0 && i + already_match < ss.size() && ss[i-already_match] == ss[i+already_match]) ++already_match;
            FINISH: f[i] = already_match;
            int actual_len = ss[i] == kSep ? (already_match / 2 * 2) : (already_match - 1) / 2 * 2 + 1;
            //cout << "i= " << i <<" already_match=" << already_match << "  actual_len=" << actual_len << endl;
            ans += (actual_len + 1) / 2;
            if (i + already_match > ed)
            {
                ed = i + already_match;
                edi = i;
            }
        }
        return ans;
    }
};