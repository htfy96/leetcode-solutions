class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        array<int, 26> platecnt {};
        int distinct_chars = 0;
        for (char c: licensePlate)
            if (isalpha(c) && !(platecnt[tolower(c) - 'a']++))
                distinct_chars++;
        string ans; bool found = false;
        for (auto&& word: words)
        {
            auto buf = platecnt;
            int need_to_fulfill = distinct_chars;
            for (char c: word)
                if (isalpha(c) && !(--buf[tolower(c) - 'a']))
                    --need_to_fulfill;
            if (!need_to_fulfill && (!found || word.size() < ans.size()))
            {
                found = true;
                ans = word;
            }
        }
        return ans;
        
    }
};