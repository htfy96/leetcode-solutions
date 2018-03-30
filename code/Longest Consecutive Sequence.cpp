class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> lens;
        for (int v: nums) {
            auto it = lens.find(v);
            if (it != lens.end()) continue;
            lens[v] = 0;
            it = lens.find(v);
           // cout << "processing v=" << v << endl;
            auto left_it = lens.find(v-1);
            auto right_it = lens.find(v+1);
            int new_len = 1;
            if (left_it != lens.end()) {
                new_len += left_it->second;
                left_it = lens.find(v - left_it->second);
            }
            else
                left_it = it;
            if (right_it != lens.end()) {
                new_len += right_it->second;
                right_it = lens.find(v + right_it->second);
            } else
                right_it = it;
            left_it->second = new_len;
            right_it->second = new_len;
            ans = max(ans, new_len);
        
        }
        return ans;
    }
};