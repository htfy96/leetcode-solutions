class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int, int>> ans; ans.reserve(people.size());
        sort(people.begin(), people.end(), [](const pair<int, int> &a, const pair<int, int> &b) { 
            return a.first != b.first ? a.first > b.first : a.second < b.second;
        });
        for (auto &&p: people)
        {
            ans.resize(ans.size() + 1);
            for (int i = ans.size() - 1; i >= p.second + 1; --i)
                ans[i] = ans[i-1];
            ans[p.second] = p;
        }
        return ans;
    }
};