class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> v((amount + 1) * coins.size());
        if (coins.empty()) return amount ? 0 : 1;
        #define idx(x, y) ((x) * coins.size() + (y))
        for (int j=0; j<coins.size(); ++j)
            v[idx(0, j)] = 1;
        for (int i=1; i<=amount; ++i)
            for (int j=0; j<coins.size(); ++j)
            {
                v[idx(i, j)] = (i >= coins[j] ? v[idx(i - coins[j], j)] : 0) + (j ? v[idx(i, j-1)] : 0);
                //cout << i << " " << j << "  " << v[idx(i, j)] << endl;
            }
        return v[idx(amount, coins.size() - 1)];
    }
};