class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        vector<bool> v((s1.size() + 1) * (s2.size() + 1) );
        if (s3.empty())
            return true;
        const int BASE = s2.size() + 1;
        v[0] = true;
        bool ans = false;
        for (int i=0; i<=s1.size(); ++i)
            for (int j=0; j<=s2.size(); ++j)
                if ((i || j) && i+j<=s3.size())
                {
                    if (i && s1[i-1] == s3[i+j-1])
                        v[i * BASE + j] = v[(i-1) * BASE + j] | v[i * BASE + j];
                    if (j && s2[j-1] == s3[i+j-1])
                        v[i * BASE + j] = v[i * BASE + j-1] | v[i * BASE + j];
                    if (i + j == s3.size() && i == s1.size() && j == s2.size() && (i || s1.empty()) && (j || s2.empty()))
                        ans |= v[i* BASE + j];
                }
        return ans;
    }
};