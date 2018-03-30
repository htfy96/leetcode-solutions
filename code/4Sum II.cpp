class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map< int, int > m; int ans = 0;
        for (int i=0; i<A.size(); ++i)
            for (int j=0; j<B.size(); ++j)
                ++m[A[i] + B[j]];
        for (int i=0; i<C.size(); ++i)
            for (int j=0; j<D.size(); ++j)
            {
                int key = 0 - C[i] - D[j];
                auto it = m.find(key);
                if (it != m.end())
                    ans += it->second;
            }
        return ans;
    }
};