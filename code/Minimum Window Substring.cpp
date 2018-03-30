class Solution {
public:
    string minWindow(string s, string t) {
        array<int, 256> cnt {}, curcnt {};
        for (char c: t)
            ++cnt[c];
        curcnt = cnt;
        int remain = 0;
        int next_idx = 0;
        for (int i=0; i<cnt.size(); ++i)
            if (cnt[i]) ++remain;
        int ans_start = 0, ans_len = 99999;
        for (int i=0; i<=s.size(); ++i)
        {
            
            if (i) {
                if (!cnt[s[i-1]]) goto POP_FINISH;
                if (!curcnt[s[i-1]]) ++remain;
                ++curcnt[s[i-1]];
            }
            //cout << "i=" << i << " remain=" << remain << endl;
            POP_FINISH: for (;remain && next_idx < s.size(); ++next_idx) {
                if (!cnt[s[next_idx]]) continue;
                --curcnt[s[next_idx]];
                if (!curcnt[s[next_idx]]) --remain;
            }
            if (remain) break;
            if (next_idx - i < ans_len) {
                ans_len = next_idx - i;
                ans_start = i;
            }
            //cout << "pos=" << i << " next_idx=" << next_idx << endl;
        }
        if (ans_len < 90000)
            return s.substr(ans_start, ans_len);
        else
            return "";
        
    }
};