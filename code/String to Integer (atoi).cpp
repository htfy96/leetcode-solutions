class Solution {
public:
    int myAtoi(string str) {
        int pos = 0;
        // ignore leading whitespace
        while (pos < str.size() && isblank(str[pos])) ++pos;
        if (pos == str.size()) return 0;
        
        // parse sign
        bool sign = true;
        if (pos < str.size() && (str[pos] == '+' || str[pos] == '-'))
        {
            if (str[pos] == '-') sign = !sign;
            ++pos;
        }
        if (pos == str.size()) return 0;
        
        // parse num
        long long num = 0; int cnt = 0;
        while (pos < str.size() && isdigit(str[pos]))
        {
            ++cnt;
            num = num * 10 + (str[pos] - '0');
            ++pos;
            if (sign && num > INT_MAX) return INT_MAX;
            if (!sign && -num < INT_MIN) return INT_MIN;
        }
        if (!cnt) return 0;
        return sign ? num : -num;
    }
};