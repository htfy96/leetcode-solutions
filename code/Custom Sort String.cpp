class Solution {
public:
    string customSortString(string S, string T) {
        int a[26]{};
        for (char c: T)
            a[c-'a']++;
        string result;
        for (int i=0; i<S.size(); ++i)
        {
            int idx = S[i] - 'a';
            while (a[idx]-- > 0) result.push_back(S[i]);
        }
        for (int i=0; i<26; ++i)
            while (a[i]-- >0)result.push_back('a' + i);
        return result;
    }
};