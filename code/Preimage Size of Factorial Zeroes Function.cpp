class Solution {
    static long long count_k(long long x, int k) { // count number of k in x!
        long long w = k, ans = 0;
        while (w <= x) {
            ans += x / w;
            w *= k;
        }
        //cout << "count " << x << " k=" << k << " =" << ans << endl;
        return ans;
    }
    
    static long find_lower_bound(int count, int k) {
        long long l = 0,  r = 5000000000L;
        //cout << "count=" << count << " k=" << k << endl;
        while (l<r-4)
        {
            
            long long mid = l + (r-l)/ 2;
            long long cnt = count_k(mid, k);
            //cout << "l=" << l << " r=" << r << " cnt=" << cnt << '\t';
            if (cnt < count) l = mid + 1; else if (cnt == count) r = mid; else r = mid - 1;
        }
        for (long long i=l; i<=r; ++i)
            if (count_k(i, k) >= count) return i;
        return l;
    }
public:
    int preimageSizeFZF(int K) {
        constexpr long kUpperBound = 10000000000L;
        const long first_2 = find_lower_bound(K, 2),
            end_2 = find_lower_bound(K+1, 2),
            first_5 = find_lower_bound(K, 5),
            end_5 = find_lower_bound(K+1, 5);
        //if (count_k(first_2, 2) != K || count_k(first_5, 5) != K) return 0;
        cout << "first_2 = " << first_2 << " end_2=" << end_2 << " first_5=" << first_5 << " end_5=" << end_5 << endl;
        
        const long first = max(first_2, first_5), ed = max(end_2, end_5);
        if (min(count_k(first, 2), count_k(first, 5)) != K) return 0;
        return max(0L, ed - first);
    }
};