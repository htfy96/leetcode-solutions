/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
    long long angle(Point a, Point b)
    {
        long double dx = b.x - a.x, dy = b.y - a.y;
        if (dy < 0) { dx = -dx; dy = -dy; }
        if (dy == 0) { dx = fabs(dx); }
     //   cout << "a=(" << a.x << "," << a.y << ") b=(" << a.x << "," << a.y << ")" << " ans=" << atan2(dy, dx) << " normal=" << round(atan2(dy, dx) * (1 << 24)) << endl;
        return round(atan2(dy, dx) * (1LL << 60));
    }
public:
    int maxPoints(vector<Point>& points) {
        if (points.empty()) return 0;
        int ans = 1;
        for (auto &&p : points)
        {
            int curans = 0; int inter = 0;
            unordered_map<long long, int> m;
            for (auto && pp: points)
                if (p.x != pp.x || p.y != pp.y)
                {
                    m[angle(p, pp)]++;
                    int cnt = m[angle(p, pp)];
                    curans = max(curans, cnt);
                }
                else
                ++inter;
            ans = max(ans, inter + curans);
        }
        return ans;
    }
};