class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        double l = 0, r = 10000000;
        while (r-l > 5e-7) {
            double mid = (r+l) / 2;
            int cnt = 0;
            for (int i=0; i<stations.size() - 1; ++i) {
                double add = (stations[i+1] - stations[i]) / mid;
                if (add < 1.0000001) continue;
                cnt += (int)add;
                if (cnt > K) break;
            }
            if (cnt > K) l = mid; else r = mid;
        }
        return r;
    }
};