class Solution {

    struct Op
    {
        char op;
    };

    inline int pred(char op)
    {
        switch (op)
        {
            case '(':
                return 0;
                break;
            case '+':
            case '-':
                return 1;
                break;
            default:
                throw runtime_error("invalid op");
        }
    }

    inline int pred(Op op)
    {
        return pred(op.op);
    }


    struct Token
    {
        int number;
        char op;
        enum {OP, NUMBER, TEOF} type;
    };


    Token getToken(istream &is)
    {
        while (!is.eof() && isspace(is.peek())) is.get();
        if (is.eof())
            return Token { 0, '\0', Token::TEOF };
        else
        {
            char lookahead = is.peek();
            if (isdigit(lookahead))
            {
                int num = 0;
                while (!is.eof() && isdigit(is.peek()))
                    num = num * 10 + (is.get() - '0');
                return Token { num, '\0', Token::NUMBER };
            }
            else
                if (lookahead == '+' || lookahead == '-' || lookahead == '(' || lookahead == ')')
                    return Token { 0, is.get(), Token::OP };
            throw runtime_error("Invalid lookahead");
        }
    }


    int apply(char op, int a, int b)
    {
        switch (op)
        {
            case '+':
                return a+b;
                break;
            case '-':
                return a-b;
                break;
            default:
                throw runtime_error("Invalid op type in apply");
        }
    }

    public:
    int calculate(string s) {
        istringstream iss(s);
        stack<int> snum;
        stack<Op> sop;

        for (Token token = getToken(iss); token.type != Token::TEOF; token = getToken(iss))
        {
            //cout << "Parsing token " << token.type << " num: " << token.number << " op:" << token.op << endl;
            switch(token.type)
            {
                case Token::NUMBER:
                    snum.push(token.number);
                    break;
                case Token::OP:
                    switch (token.op)
                    {
                        case '+':
                        case '-':
                            {
                                while (!sop.empty() && pred(sop.top()) >= pred(token.op))
                                {
                                    Op o = sop.top(); sop.pop();
                                    int b = snum.top(); snum.pop();
                                    int a = snum.top(); snum.pop();
                                    snum.push(apply(o.op, a, b));
                                    //cout << "Applying " << o.op << " onto " << a << " " << b << endl;
                                }
                                Op newo { token.op };
                                sop.push(newo);
                                break;
                            }
                        case '(':
                            {
                                Op newo { token.op };
                                sop.push(newo);
                                break;
                            }
                        case ')':
                            {
                                while (sop.top().op != '(')
                                {
                                    Op o = sop.top(); sop.pop();
                                    int b = snum.top(); snum.pop();
                                    int a = snum.top(); snum.pop();
                                    snum.push(apply(o.op, a, b));
                                    //cout << "Applying " << o.op << " onto " << a << " " << b << endl;
                                }
                                sop.pop();
                                break;
                            }
                        default:
                            throw runtime_error("Invalid op");
                    }
            }
        }

        while (!sop.empty())
        {
            Op o = sop.top(); sop.pop();
            int b = snum.top(); snum.pop();
            int a = snum.top(); snum.pop();
            snum.push(apply(o.op, a, b));
            //cout << "Applying " << o.op << " onto " << a << " " << b << endl;
        }
        return snum.top();
    }
};
