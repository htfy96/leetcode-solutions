class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        stack<int> ss;
        for (int i=0; i<s.size(); ++i)
            switch(s[i])
            {
                case '(':
                    ss.push(i);
                    break;
                case ')':
                    if (!ss.empty() && s[ss.top()] == '(')
                    {
                        int last_left = ss.top();
                        ss.pop();
                    } else 
                        ss.push(i);
            }
        if (ss.empty()) return s.size();
        int last = s.size();
        while (!ss.empty())
        {
            ans = max(ans, last - ss.top() - 1);
            last = ss.top();
            ss.pop();
        }
        ans = max(ans, last);
        return ans;
    }
};