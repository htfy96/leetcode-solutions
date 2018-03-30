class Solution {
    int kthImpl(int* st, int *ed, int k) {
        if (ed - st == 1) return *st;
        if (ed - st == 2) { if (st[0] > st[1]) swap(st[0], st[1]); return st[k]; }
        int* pivot_ptr = st + static_cast<int>(0.618 * distance(st, ed));
        iter_swap(st, pivot_ptr);
        int *pi = st + 1, *pj = st + 1;
        for (;pj < ed; ++pj)
            if (*pj <= *st)
                iter_swap(pi++, pj);
        iter_swap(pi - 1, st);
        int pivot_idx = distance(st, pi - 1);
        if (k < pivot_idx) return kthImpl(st, pi-1, k);
        else if (k == pivot_idx) return *(pi - 1);
        else return kthImpl(pi, ed, k - pivot_idx - 1);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        k = nums.size() - k;
        return kthImpl(nums.data(), nums.data() + nums.size(), k);
    }
};