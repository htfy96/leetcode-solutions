class Solution {
    static int get_prior(char c)  {
        if (c == '(') return -100;
        if (c == ')') return 100;
        if (c == '+' || c == '-') return 1;
        if (c == '*' || c == '/') return 2;
    }
    
    static void process(char op, stack<long long>& s) {
        long long v2 = s.top(); s.pop();
        long long v1 = s.top(); s.pop();
        switch(op) {
            case '+':
                s.push(v1 + v2);
                break;
            case '-':
                s.push(v1 - v2);
                break;
            case '*':
                s.push(v1 * v2);
                break;
            case '/':
                s.push(v1 / v2);
                break;
        }
    }
public:
    int calculate(string s) {
        
        s.push_back('$');
        istringstream iss(s);
        stack<long long> si; stack<char> ops;
        while (iss.good()) {
            while (isblank(iss.peek())) iss.get();
            if (!iss.good()) break;
            if (isdigit(iss.peek())) {
                long long x; iss >> x;
                si.push(x);
                //cout << "pushed " << x << endl;
                continue;
            }

            char curop; iss >> curop;
            //cout << "processing " << curop << endl;
            switch(curop) {
                case '(':
                    ops.push('(');
                    break;
                case ')':
                    while (ops.top() != '(') {
                        char op = ops.top();
                        ops.pop();
                        process(op, si);
                    }
                    ops.pop();
                    break;
                case '$':
                    while (!ops.empty()) {
                        char op = ops.top();
                        ops.pop();
                        process(op, si);
                    }
                    break;
                default:
                    while (!ops.empty() && get_prior(ops.top()) >= get_prior(curop)) {
                        char op = ops.top();
                        ops.pop();
                        process(op, si);
                    }
                    ops.push(curop);
            }
        }
        return si.top();
    }
};