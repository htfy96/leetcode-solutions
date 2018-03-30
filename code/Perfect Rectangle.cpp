

class Solution {
    struct Interval
{
    int from, to;
    friend bool operator<(const Interval &a, const Interval &b)
    {
        return a.from != b.from ? a.from < b.from : a.to < b.to;
    }
    friend bool operator==(const Interval &a, const Interval &b)
    {
        return a.from == b.from && a.to == b.to;
    }
};
struct Event
{
    enum Type {REMOVE, ADD, TIMEFINISH} type;
    Interval interval;
    int time;
    Event(Type type, int from, int to, int time):
        type(type), interval({from, to}), time(time) {}
    friend bool operator<(const Event&a, const Event &b)
    {
        return a.time != b.time ? a.time < b.time : (a.type != b.type ? (int)a.type < (int)b.type: a.interval.from < b.interval.from);
    }
    
    friend bool operator==(const Event &a, const Event &b)
    {
        return a.time == b.time && a.interval.from == b.interval.from && a.interval.to == b.interval.to && a.type == b.type;
    }
};


public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        vector<Event> events;
        for (auto &&rect: rectangles)
        {
            events.push_back(Event(Event::ADD, rect[1], rect[3], rect[0]));
            events.push_back(Event(Event::REMOVE, rect[1], rect[3], rect[2]));
            events.push_back(Event(Event::TIMEFINISH, -1, -1, rect[0]));
            events.push_back(Event(Event::TIMEFINISH, -1, -1, rect[2]));
        }
        sort(events.begin(), events.end());
        auto new_end = unique(events.begin(), events.end(), [](const Event &a, const Event &b) {
            return a.type == Event::TIMEFINISH && b.type == Event::TIMEFINISH && a.time == b.time;
        });
        events.erase(new_end, events.end());
        
        Interval whole {-100000, -100000};
        bool finished = false;
        
        multiset<Interval> s;
        for (auto &&e: events)
        {
            //cout << "Event: time=" << e.time << " type=" << (int)e.type << " from=" << e.interval.from << " to=" << e.interval.to << endl;
            switch(e.type)
            {
                case Event::ADD:
                {
                        s.insert(e.interval);
                        break;
                }
                case Event::REMOVE:
                {
                    //for (auto &&itvl: s)
                    //{
                     //   cout << "itvl in set: from=" << itvl.from << " to=" << itvl.to << endl;
                    //}
                    auto it = s.find(e.interval);
                    assert(it != s.end());
                    s.erase(it);
                    break;
                }
                case Event::TIMEFINISH:
                {
                    int last = -100000;
                    for (auto &&itvl: s)
                    {
                        if (last != -100000 && itvl.from != last)
                            return false;
                        last = itvl.to;
                    }
                    if (s.empty())
                    {
                        finished = true;
                        break;
                    }
                    Interval cur {s.begin()->from, s.rbegin()->to};
                    if (whole.from == -100000)
                        whole = cur;
                    else
                    {
                        if (finished)
                            return false;
                        if (!(cur == whole))
                            return false;
                    }
                    break;
                }
            }
        }
        return true;
        
    }
};
