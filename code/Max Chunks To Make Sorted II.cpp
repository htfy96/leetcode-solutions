class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> sorted = arr;
        sort(sorted.begin(), sorted.end());
        vector<int> prehash; vector<long long> presum;
        for (int v: sorted) {
            prehash.push_back(prehash.empty() ? v : *prehash.rbegin() ^ v);
            presum.push_back(presum.empty() ? v : *presum.rbegin() + v);
        }
        vector<int> f(arr.size(), -100);
        for (int i=0; i<arr.size(); ++i)
        {
            int cur_hash = 0; long long cur_sum = 0;
            //multiset<int> in_set;
            for (int j=i; j>=0; --j)
            {
                cur_hash ^= arr[j];
                cur_sum += arr[j];
                //in_set.insert(arr[j]);
                
                const int target_hash = j ? prehash[i] ^ prehash[j-1] : prehash[i];
                const long long target_sum = j ? presum[i] - presum[j-1] : presum[i];
                bool ok = false;
                if (cur_hash == target_hash && cur_sum == target_sum) {
                    int idx = 0; ok = true;
                    //for (auto&& v: in_set) {
                    //    if (v != sorted[j + idx]) ok = false;+
                    //   ++idx;
                    //}
                }
                if (ok) {
                    //cout << "ok! i=" << i << " j=" << j << endl; 
                    f[i] = max(f[i], (j ? f[j-1] : 0) + 1); 
                }
            }
        }
        return f[arr.size() - 1];
    }
};