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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ans;
        
        for (auto &&it: intervals)
        {
            if (it.end >= newInterval.start && it.start <= newInterval.end)
            {
                newInterval.start = min(newInterval.start, it.start);
                newInterval.end = max(newInterval.end, it.end);
            }
        }
        
        bool flag = false;
        for (auto &&it: intervals)
            if (it.end >= newInterval.start && it.start <= newInterval.end)
            {
                // do nothing
            }
            else
            {
                if (it.start > newInterval.start && !flag)
                {
                    flag = true;
                    ans.push_back(newInterval);
                }
                ans.push_back(it);
            }
        if (!flag)
            ans.push_back(newInterval);
        return ans;
    }
};