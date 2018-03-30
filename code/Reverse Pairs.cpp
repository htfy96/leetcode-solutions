class Solution {
    struct Result
    {
        vector<int> sorted;
        int res = 0;
        Result() = default;
        Result(const vector<int> &v, int res): sorted(v), res(res) {}
        friend ostream &operator<<(ostream &o, const Result &res)
        {
            o << "sorted: len=" << res.sorted.size() << "\t";
            for (auto &&item: res.sorted)
            {
                o << item << " ";
            }
            o << "\t";
            o << "res=" << res.res;
            return o;
        }
    };
    
    Result calc(vector<int>& nums, int l, int r)
    {
        if (l==r)
            return Result ( vector<int>(1, nums[l]), 0 );
        int mid = (l+r) / 2;
        Result res1 = calc(nums, l, mid), res2 = calc(nums, mid+1, r);
        
        auto  it2 = res2.sorted.begin();
        Result ans;
        ans.res = res1.res + res2.res;
        
        for (auto it1 = res1.sorted.begin(); it1 != res1.sorted.end(); ++it1)
        {
            while (it2 != res2.sorted.end() && (long long)*it1 > 2LL * (long long)*it2) ++it2;
            ans.res += distance(res2.sorted.begin(), it2);
        }
        
    //    cout << "calc l=" << l << " r=" << r << endl;
  //      cout << "Left: " << res1 << endl;
    //    cout << "Right: " << res2 << endl;
        
        
        merge(res1.sorted.begin(), res1.sorted.end(), res2.sorted.begin(), res2.sorted.end(), back_inserter(ans.sorted));
      //  cout << "This: " << ans << endl;
        return ans;
    }
public:
    int reversePairs(vector<int>& nums) {
        if (nums.empty()) return 0;
        return calc(nums, 0, nums.size() - 1).res;
    }
};