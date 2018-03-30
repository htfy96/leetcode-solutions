class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        if (S.empty()) return {S};
        string prefix;
        int i=0;
        for (; i<S.size(); ++i)
            if (!isalpha(S[i])) {
                prefix += S[i];
                continue;
            }
            else break;
        if (i==S.size()) return {S};
        vector<string> res = letterCasePermutation(S.substr(i+1));
        vector<string> ans;
        for (auto&& s: res) {
            ans.push_back(S.substr(0, i) + (char)tolower(S[i]) + s);
            ans.push_back(S.substr(0, i) + (char)toupper(S[i]) + s);
        }
        return ans;
        
    }
};