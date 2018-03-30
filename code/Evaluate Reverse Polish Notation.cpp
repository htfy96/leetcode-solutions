class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> ss;
        for (auto&& s: tokens) {
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int v2 = ss.top(); ss.pop();
                int v1 = ss.top(); ss.pop();
                if (s == "+") ss.push(v1 + v2);
                else if (s == "-") ss.push(v1 - v2);
                else if (s == "*") ss.push(v1 * v2);
                else if (s == "/") ss.push(v1 / v2);
            } else
                ss.push(stoi(s));
        }
        return ss.top();
    }
};