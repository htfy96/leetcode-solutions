class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> vs; vs.reserve(nums.size());
        for (int v: nums)
            vs.push_back(to_string(v));
        sort(vs.begin(), vs.end(), [](const string& s1, const string& s2) { return s1 + s2 > s2 + s1; });
        string ans;
        for (auto&& s: vs)
            ans += s;
        reverse(ans.begin(), ans.end());
        while (ans.size() > 1 && *ans.rbegin() == '0') ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};