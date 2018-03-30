class Solution {
    struct Rec {
        int profit, capital;
        bool operator<(const Rec& other) const {
            return capital != other.capital ? capital < other.capital : profit < other.profit;
        }
        bool operator==(const Rec& other) const {
            return capital == other.capital ? profit < other.profit : capital < other.capital;
        }
    };
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        vector<Rec> v;
        for (int i=0; i<Profits.size(); ++i)
            v.push_back(Rec { Profits[i], Capital[i] });
        sort(v.begin(), v.end(), 
             [](Rec a, Rec b) { return a.capital < b.capital; }
        );
        priority_queue<int> pq;
        int last_ed = 0;
        for (int K=0; K<k; ++K) {
            //cout << "k=" << K << endl;
            int cur_ed = upper_bound(v.begin(), v.end(), Rec {100000, W}) - v.begin();
            //cout << "cur_ed=" << cur_ed << endl;
            for (int i=last_ed; i<cur_ed; ++i) pq.push(v[i].profit);
            //cout << "pushed" << endl;
            if (pq.empty()) break;
            W += pq.top();
            pq.pop();
            last_ed = cur_ed;
        }
        return W;
    }
};