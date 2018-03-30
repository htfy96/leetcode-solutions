class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> f(arr.size(), -100);
        for (int i=0; i<arr.size(); ++i) {
            vector<bool> marked(arr.size());
            for (int j=i; j>=0; --j)
            {
                marked[arr[j]] = true;
                bool ok = true;
                for (int k=j; k<=i; ++k)
                    if (!marked[k]) ok = false;
                if (ok) f[i] = max(f[i], (j ? f[j-1] : 0) + 1);
            }
        }
        return f[arr.size() - 1];
    }
};