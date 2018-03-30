
  struct Rec
    {
        long long rem;
        int pos;
        bool operator==(const Rec& other) const
        {
            return rem == other.rem;
        }
    };
    
    namespace std {
    template<>
    struct hash<Rec>
    {
        std::hash<long long> h;
      size_t operator() (const Rec &rec) const
      {
          return h(rec.rem);
      }
    };
    }
class Solution {
  
public:
    string fractionToDecimal(long long numerator, long long denominator) {
        bool sign = (numerator < 0) ^ (denominator < 0);
        if (numerator == 0) sign = false;
        numerator = abs(numerator); denominator = abs(denominator);
        long long before = numerator / denominator, rem = numerator % denominator;
        string ans = (!sign ? "" : "-") + to_string(before);
        if (rem == 0)
            return ans;
        ans += ".";
        
        unordered_set<Rec> v;
        string after = "";
        long long pos = 0;
        while (rem != 0 && v.find(Rec{rem, -100}) == v.end())
        {
            cout << "rem=" << rem <<" denom=" << denominator << endl;

            v.insert(Rec{rem, pos});
            ++pos;
            rem *= 10;
            after += to_string(rem / denominator);
            rem %= denominator;
            
          //  cout << "next rem=" << rem << endl;
        }

        if (rem == 0)
            return ans + after;
        else
        {
                    auto cirstart = v.find(Rec{ rem, -100})->pos;
        
            return ans + after.substr(0, cirstart) + "(" + after.substr(cirstart) + ")";
        }
    }
};