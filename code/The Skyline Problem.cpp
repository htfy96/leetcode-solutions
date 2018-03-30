class Solution {
    struct Event
    {
        enum { START, END, TIMEFINISH} type;
        int pos;
        int val;
    };
public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        vector<Event> v;
        vector<pair<int, int>> ans;
        for (auto && b: buildings)
        {
            v.push_back(Event{ Event::START, b[0], b[2]});
            v.push_back(Event { Event::END, b[1], b[2]});
            v.push_back(Event {Event::TIMEFINISH, b[1], -1});
            v.push_back(Event {Event::TIMEFINISH, b[0], -1});
        }
        sort(v.begin(), v.end(), [](const Event &a, const Event &b) { return a.pos != b.pos ? a.pos < b.pos : (int)a.type < (int)b.type; });
        auto ed = unique(v.begin(), v.end(), [](const Event &a, const Event &b) { return a.pos == b.pos && a.type == Event::TIMEFINISH && b.type == Event::TIMEFINISH; });
        v.erase(ed, v.end());
        multiset<int> s;
        for (auto &&e: v)
        {
            switch (e.type) 
            {
                case Event::START:
                    s.insert(e.val);
                    break;
                case Event::END:
                    s.erase(s.find(e.val));
                    break;
                case Event::TIMEFINISH:
                {
                    int res = s.empty() ? 0 : *s.rbegin();
                    if (ans.empty() || ans.rbegin()->second != res)
                        ans.push_back(make_pair(e.pos, res));
                }
            }
        }
        return ans;
    }
};