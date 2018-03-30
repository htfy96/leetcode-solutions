class Solution {
public:
    string decodeString(string s) {
        reverse(s.begin(), s.end());
        cout << s << endl;
        cout << s.length() << endl;
        stack<char> ss;
        if (s.empty()) return "";
        istringstream iss(s);
        ostringstream oss;
        while (iss.good() && !iss.eof()) {
            char c = iss.get();
            cout << "get" << c << endl;
            if (!isalnum(c) && c != '[' && c != ']') break;
            switch(c) {
                case '[': {
                    int times = 0; int power = 1;
                    while (iss.good() && isdigit(iss.peek())) {
                        char x = iss.get();
                        times += power * (x - '0');
                        power *= 10;
                    }
                    if (!times) times = 1;
                    string times_str = to_string(times);
                    times = stoi(times_str);
                    string tmp;
                    while (ss.top() != ']') {
                        tmp += ss.top();
                        ss.pop();
                    }
                    ss.pop();
                    reverse(tmp.begin(), tmp.end());
                    while (times--)
                        for (char c: tmp)
                            ss.push(c);
                    break;
                }
                default:
                    ss.push(c);
            }
        }
        string ans;
        while (!ss.empty()) { ans.push_back(ss.top()); ss.pop(); }
        //reverse(ans.begin(), ans.end());
        return ans;
    }
};