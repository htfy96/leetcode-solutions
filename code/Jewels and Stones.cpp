class Solution {
public:
    int numJewelsInStones(string J, string S) {
        bool is_jewel[256]{};
        for (char c: J) is_jewel[c] = true;
        int ans = 0;
        for (char c: S)
            if (is_jewel[c]) ++ans;
        return ans;
    }
};