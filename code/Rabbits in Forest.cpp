class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int, int> m;
        for (int v: answers)
            m[v]++;
        int ans = 0;
        for (auto&& item: m)
        {
            int k = item.first;
            int cnt = item.second;
            ans += static_cast<int>(cnt * 1.0 / (k+1) + 0.999) * (k+1);
        }
        return ans;
    }
};