class Solution {
    struct Line
    {
        int x1, y1, x2, y2;
    };
    
    bool on_seg(int x, int y, int x1, int y1, int x2, int y2)
    {
        return (x - x1) * (y - y2) - (x - x2) * (y - y1) == 0 && (x - x1) * (x2 -x) + (y - y1) * (y2 - y) >=0;
    }
    bool cross(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
    {
        if (on_seg(x1, y1, x3, y3, x4, y4) || on_seg(x2, y2, x3, y3, x4, y4)) return true;
        long v1x = x2 - x1, v1y = y2 - y1;
        long v2x = x3 - x1, v2y = y3 - y1;
        long v3x = x4 - x1, v3y = y4 - y1;
        return (v1x * v2y - v1y * v2x) * (v1x * v3y - v1y * v3x) <0;
    }
    
    bool check(Line l, const vector<Line> &v)
    {
        if (!v.empty())
        for (int i=0; i<v.size() - 1; ++i)
        {
            Line line = v[i];
            if (cross(l.x1, l.y1, l.x2, l.y2, line.x1, line.y1, line.x2, line.y2) && 
                cross(line.x1, line.y1, line.x2, line.y2, l.x1, l.y1, l.x2, l.y2))
            {
               // cout << "("<<l.x1 << "," << l.y1<<") <-> ("<<l.x2 << ","<<l.y2 << ") crossed with (" <<
               //     line.x1 << "," << line.y1 << ") <-> (" << line.x2 << "," << line.y2 << ")" << endl;
                return true;
            } else {
             //   cout << "("<<l.x1 << "," << l.y1<<") <-> ("<<l.x2 << ","<<l.y2 << ") uncrossed with (" <<
              //      line.x1 << "," << line.y1 << ") <-> (" << line.x2 << "," << line.y2 << ")" << endl;
            }
        }
        return false;
    }
    
    void add(Line line, vector<Line> &l)
    {
        l.push_back(line);
        if (l.size() > 8)
            l.erase(l.begin());
    }
    
public:
    bool isSelfCrossing(vector<int>& x) {
        vector<Line> lines; // -- ||
        int xx =0, yy = 0;
        for (int i=0; i<x.size(); ++i)
            switch(i % 4)
            {
                case 0: //up
                    {
                        Line l {xx, yy, xx, yy+x[i]};
                        if (check(l, lines))
                            return true;
                        yy += x[i];
                        add(l, lines);
                        break;
                    }
                case 1: // left
                {
                        Line l {xx, yy, xx-x[i], yy};
                        if (check(l, lines))
                            return true;
                        xx -= x[i];
                        add(l, lines);
                        break;                    
                }
                case 2: // down
                {
                        Line l {xx, yy, xx, yy-x[i]};
                        if (check(l, lines))
                            return true;
                        yy -= x[i];
                        add(l, lines);
                        break;                    
                }
                case 3: // right
                {
                        Line l {xx, yy, xx+x[i], yy};
                        if (check(l, lines))
                            return true;
                        xx += x[i];
                        add(l, lines);
                        break;                      
                }
            }
        return false;
    }
};