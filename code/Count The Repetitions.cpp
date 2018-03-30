class Solution {
    vector<int> getLen(const string &s1, const string &s2)
    {
        vector<int> ans;
        for (int start = 0; start < s1.size(); ++start)
        {
            int p = start; int last = start; int p2 = 0;
            while (p2 < s2.size() && p - last <= s1.size())
            {
                if (s1[p % s1.size()] == s2[p2])
                {
                    ++p;
                    ++p2;
                    last = p;
                }
                else
                ++p;
            }
            ans.push_back(p - last <= s1.size() ? p - start: INT_MAX / 16);
        }
        return ans;
    }
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        auto d = getLen(s1, s2);
        decltype(d) l(d.size(), 1);
        auto exd = d;
        
        for (int i=l.size() - 1; i>=0; --i)
        {
            if (exd[i] + i < l.size() && i + exd[i] + exd[i + exd[i]] < l.size())
            {
                l[i] = l[i+exd[i]] + 1;
                exd[i] = exd[i] + exd[i + exd[i]];
            }
        }
        int p = 0;
        int cnt = 0;
        while(p + d[p%s1.size()] <= n1 * s1.size())
        {
          //  cout << "at p=" << p << "d=" << d[p % s1.size()] << endl;
          if (p + exd[p%s1.size()] <= n1 * s1.size())
          {
              cnt += l[p%s1.size()];
              p += exd[p%s1.size()];
          } else
          {
              cnt++;
              p += d[p%s1.size()];
          }
        }
        return cnt / n2;
    }
};