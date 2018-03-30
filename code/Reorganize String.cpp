class Solution {
public:
    string reorganizeString(string S) {
        string ans;
        vector<int> cnt(26);
        for (char c: S) {
            cnt[c-'a']++;
        }
        int W = S.length();
        while (W--) {
            int maxc = -1; const int last = !ans.empty() ? *ans.rbegin() - 'a' : 123;
            //cout << "W=" << W << "last=" << last << endl;
            for (int i=0; i<26; ++i)
                if (i != last && (maxc < 0 || cnt[i] > cnt[maxc]))
                    maxc = i;
            if (maxc == last || cnt[maxc] <= 0) break;
            cnt[maxc]--;
            ans.push_back('a' + maxc);
        }
        if (W >= 0) return "";
        return ans;
    }
};