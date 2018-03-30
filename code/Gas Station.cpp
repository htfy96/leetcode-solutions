class Solution {
    struct {
        int mi; // mi = Min{0, min{prefix_sums}
        void add(int x) {
            mi = min(mi, x);
        }
        void addAll(int x) {
            mi += x;
        }
    } prefix_sums;
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int s = 0;
        for (int i=0; i<gas.size(); ++i) {
            s += gas[i] - cost[i];
            prefix_sums.add(s);
        }
        if (prefix_sums.mi >= 0) return 0;
        for (int i=0; i<gas.size(); ++i) {
            prefix_sums.addAll(-(gas[i] - cost[i]));
            prefix_sums.add(s);
            if (prefix_sums.mi >= 0) return (i+1) % gas.size();
        }
        return -1;
    }
};