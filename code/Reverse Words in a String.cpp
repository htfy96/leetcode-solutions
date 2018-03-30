class Solution {
public:
    void reverseWords(string &s) {
        int out_idx = 0;
        bool not_first = false;
        for (int i=0; i<s.size(); ++i)
            if (s[i] != ' ') {
                s[out_idx++] = s[i];
                not_first = true;
            }
            else
                if (s[i] == ' ' && i+1 < s.size() && s[i+1] != ' ' && not_first)
                    s[out_idx++] = s[i];
        s.resize(out_idx);
        
        reverse(s.begin(), s.end());
        int last_start = 0;
        for (int i=0; i<=s.size(); ++i)
            if (i == s.size() || s[i] == ' ') {
                reverse(s.begin() + last_start, s.begin() + i);
                last_start = i+1;
            }
            
        
        
    }
};