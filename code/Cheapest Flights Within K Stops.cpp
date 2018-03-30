class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<long long> d(n, INT_MAX);
        d[src] = 0;
        vector<vector<pair<int, int>>> a(n);
        for (auto&& v: flights) {
            a[v[0]].push_back(make_pair(v[1], v[2]));
        }
        ++K;
        while (K--) {
            vector<long long> d_next = d;
            for (int i=0; i<n; ++i) 
                for (auto p: a[i])
                    d_next[p.first] = min(d_next[p.first], d[i] + p.second);
            d = std::move(d_next);
        }
        return d[dst] == INT_MAX ? -1 : d[dst];
    }
};