class Solution {
    vector<string> calc(const string &s, int part)
    {
        if (part == 4)
            return s.empty() ? vector<string> {""} : vector<string>();
        if (s.empty()) return vector<string>{};
        int pos = 0;
        string ss = string(1, s[0]);
        int z = s[0] == '0';
        vector<string> ans;
        for (int len = 1; len <= min((int)s.size(), 3); ++len)
        {
            string prefix = s.substr(0, len);
            int z = count(prefix.cbegin(), prefix.cend(), '0');
            if (prefix != "0" && prefix[0] == '0') break;
            
            if (stoi(prefix) >= 256) break;
            auto res = calc(s.substr(len), part + 1);
            for (auto &str: res)
                str = prefix + "." + str;
            move(res.begin(), res.end(), back_inserter(ans));
        }
        return ans;
        
        
    }
public:
    vector<string> restoreIpAddresses(string s) {
        auto ans = calc(s, 0);
        for_each(ans.begin(), ans.end(), [](string &s) { s.pop_back(); });
        return ans;
    }
};