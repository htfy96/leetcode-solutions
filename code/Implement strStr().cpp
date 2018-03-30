
class Solution {
public:
    __attribute__((optimize("Ofast", "tree-vectorize"))) 
        int strStr(const string& haystack, const string& needle) {
        unsigned long long hneedle = 0, hw = 1;
        constexpr unsigned long long kHashFactor = 31;
        // Calculate BKDRHash(needle)
        // = Sum { needle[i] * kHashFactor^(needle.size() - 1 - i) }
        for (int i=0; i<needle.size(); ++i) {
            hneedle = hneedle * kHashFactor + needle[i];
            if (i) hw *= kHashFactor;
        }
        // hneedle = BKDRHash(needle), hw = kHashFactor ^ (needle.size() - 1)
        unsigned long long hwindow = 0;
        if (needle.empty()) return 0;
        for (int i=0; i<haystack.size(); ++i) {
            hwindow = hwindow * kHashFactor + haystack[i];
            // hwindow = BKDRHash( haystack.substr(i - needle.size() - 1, needle.size()) )
            if (i+1>=needle.size()) {
                if (hwindow == hneedle) {
                    const int start_idx = i + 1 - needle.size();
                    for (int j=0; j<needle.size(); ++j)
                        if (haystack[start_idx + j] != needle[j])
                            goto COMPARE_END;
                    return start_idx;
                }
                
                COMPARE_END:
                hwindow -= hw * haystack[i+1-needle.size()];
            }
        }
        return -1;
        
    }
};