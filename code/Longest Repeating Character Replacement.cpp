class Solution {
    struct Cmp
    {
        bool operator() (const pair<int, int>& a, const pair<int, int> &b) const
        {
            return a.first != b.first ? a.first < b.first : a.second < b.second;
        }
    };
public:
    int characterReplacement(string s, int k) {
        int cnt[26];
        memset(cnt, 0, sizeof(cnt));
        multiset <pair<int, int>, Cmp> rev; // cnt, idx
        for (int i=0; i<26; ++i)
        {
            rev.insert(make_pair(0, i));
        }
        
        queue<char> q;
        size_t ans = 0;
        
        for (size_t i=0; i<s.size(); ++i)
        {
            char c = s[i];
            q.push(c);
            auto it = rev.find(make_pair(cnt[c - 'A'], c - 'A'));
            rev.erase(it);
            
            ++cnt[c-'A'];
            rev.insert(make_pair(cnt[c-'A'], c-'A'));
            
            while (q.size() - rev.rbegin()->first > k)
            {
                char popC = q.front();
                q.pop();
                auto it = rev.find(make_pair(cnt[popC - 'A'], popC - 'A'));
                rev.erase(it);
                --cnt[popC - 'A'];
                rev.insert(make_pair(cnt[popC - 'A'], popC - 'A'));
            }
            
            //cout << "pos = "<< i << "  q.size() = "<<q.size()  << endl;
            
            ans = max(ans, q.size());
        }
        return ans;
        
    }
};