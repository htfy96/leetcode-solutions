class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int last = 0;
        bool c[256] {};
        while (last < s.size() && !c[s[last]]) {
            c[s[last++]] = true;
        }
        int ans = 0;
        ans = max(ans, last);
        for (int i=0; i<s.size(); ++i) {
            c[s[i] ] = false;
            while (last < s.size() && !c[s[last]]) {
            c[s[last++]] = true;
        }
            ans = max(ans, last - (i+1));
        }
        return ans;
    }
};