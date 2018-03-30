class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int s = 0;
        unordered_map<int, int> m;
        m[0]++;
        int ans = 0;
        for (int v: nums)
        {
            s += v;
            //cout << "s=" << s << endl;
            //cout << "ans=" << ans << endl;
            auto it = m.find(s-k);
            if (it != m.end())
                ans += it->second;
            m[s]++;
        }
        return ans;
    }
};