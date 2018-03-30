class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        vector<int> pos[26];
        for (int i=0; i<S.size(); ++i)
            pos[S[i] - 'a'].push_back(i);
        for (int i=0; i<26; ++i)
            sort(pos[i].begin(), pos[i].end());
        int ans = 0;

        for (auto&& w: words)
        {
            int cur = S.size();
            bool ok = true;
            for (auto it = w.rbegin(); it != w.rend(); ++it)
            {
                char c = *it; int idx = c - 'a';
                auto t = lower_bound(pos[idx].cbegin(), pos[idx].cend(), cur);
                if (t != pos[idx].cbegin())
                    cur = *(--t);
                else {
                    ok = false;
                    break;
                }

            }
            if (ok) ++ans;
        }
        return ans;
                
    }
};