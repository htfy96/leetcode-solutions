/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {
            return a.start < b.start;
        });
        vector<Interval> ans;
        for (auto &&it: intervals)
        {
            if (ans.empty() || it.start > ans.rbegin()->end )
                ans.push_back(it);
            else
                ans.rbegin()->end = max(ans.rbegin()->end, it.end);
        }
        return ans;
    }
};