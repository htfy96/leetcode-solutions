class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        #define isnat(x) (x >= 0 && fabs(round(x) - x) <= 1e-6)
        for (;;) {
        if (tx <= 0 || ty <= 0) return false;
        if (sx == tx && sy == ty) return true;
        if (tx >= ty)
        {
            if (sy == ty && tx >= sx) {
                // check if tx - k * ty == sx
                const double k = (tx - sx) * 1.0 / ty;
                if (isnat(k)) return true;
            }
            
            tx = tx % ty;
        }
        else {
            if (sx == tx && ty >= sy) {
                // ty - k * tx == sy
                const double k = (ty - sy) * 1.0 / tx;
                if (isnat(k)) return true;
            }
            
                ty = ty % tx;
        }
        }
    }
};