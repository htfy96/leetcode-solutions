class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int l = 1,  r = nums.size() - 1;
        while (r-l > 2) {
            int mid = (l+r) / 2;
            int le_cnt = count_if(nums.cbegin(), nums.cend(), [mid](int v) { return v <= mid; });
            if (le_cnt <= mid) l = mid; else r = mid;
        }
        cout << "l=" << l << " r=" << r << endl;
        for (int i=r; i>=l-10; --i) {
            int e_cnt = count_if(nums.cbegin(), nums.cend(), [i](int v) { return v == i; });
            if (e_cnt > 1) return i;
        }
        
    }
};