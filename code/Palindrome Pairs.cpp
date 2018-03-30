namespace std
{
    template<> struct hash<pair<int, int>>
    {
        hash<int> h;
        size_t operator() (const pair<int, int> &p) const
        {
            return ((unsigned long)(h(p.first)) << 32UL) + h(p.second);
        }
    };
}

class Solution {
    static bool isPara(const string &s, int len) // s[:len] is para
    {
        for (int i=0; i<len/2; ++i)
            if (s[i] != s[len-1-i])
                return false;
        return true;
    }
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_multimap<unsigned int, int> m; // hash -> idx
        vector<vector<int>> ans;
        unordered_set<pair<int, int>> v;
        for (int i=0; i<words.size() ;++i)
        {
            auto &&str = words[i];
            unsigned int h = 0;
            for (auto c: str)
             h = h * 131 + c;
      //     cout << "word " << i <<" hash=" << h << endl;
            m.insert(make_pair(h, i));
        }
        for (int i=0; i<words.size() ;++i)
        {
        //    cout << "Processing i=" << i << " " << words[i] << endl;
            auto &&str = words[i];
            unsigned int h = 0;
            for (int j=str.length(); j>=0; --j)
            {
                if (isPara(str, j))
                {
                    auto pit = m.equal_range(h);
             //       cout << "j=" << j << " is para!" << endl;
                    for (auto it = pit.first; it != pit.second; ++it)
                    if (it->second != i)
                    {
                      //  cout << "found pairs:" << it->second << endl;
                        ans.push_back(vector<int> {it->second, i});
                        v.insert(make_pair(it->second, i));
                    }
                }

                if (j>0) h = h * 131 + str[j-1];
            }
        }
        for (int i=0; i<words.size(); ++i)
        {
            auto &&str = words[i];
            for (int j=0; j<=str.length(); ++j)
                if (j == str.length() || isPara(str.substr(j), str.length() - j))
                {
                    unsigned int h = 0;
                    for (int k = j-1; k>=0; --k)
                        h = h * 131 + str[k];
                    auto pit = m.equal_range(h);
                    for (auto it = pit.first; it != pit.second; ++it)
                        if (it->second != i && v.find(make_pair(i, it->second)) == v.end())
                        {
                            ans.push_back(vector<int> {i, it->second});
                            v.insert(make_pair(i, it->second));
                        }
                }
            
        }
        return ans;
    }
};