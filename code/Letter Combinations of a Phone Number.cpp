class Solution {
public:
    vector<string> letterCombinations(string digits) {
        queue<string> q;
        vector<string> ans;
        if (digits.empty()) return {};
        static constexpr const char* kTable[] = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        q.push("");
        while (!q.empty()) {
            string x = q.front();
            q.pop();
            if (x.size() == digits.size()) { ans.push_back(x); continue; }
            int digit = digits[x.size()] - '0';
            //cout << "digit=" << digit << endl;
            for (const char* p = kTable[digit]; *p; ++p) {
                //cout << p << endl;
               // cout << "cur= " << x << endl;
                q.push(x + *p);
               // cout << "pushed " << q.back()  << endl;
            }
        }
        return ans;
    }
};