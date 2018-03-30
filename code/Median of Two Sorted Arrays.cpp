#pragma GCC optimize("O2")
class Solution {
    using VI = vector<int>::iterator;

double findKth(VI v1a, VI v1b, VI v2a, VI v2b, int k)
{
    int da = distance(v1a, v1b), db = distance(v2a, v2b);
    //cout << k << " " << da << db << endl;
    if (da <= 0)
        return v2a[k];
    if (db <= 0)
        return v1a[k];
    switch(k)
    {
        case 0:
            return min(*v1a, *v2a);
        case 1:
            return max(findKth(v1a + 1, v1b, v2a, v2b, 0),
                        findKth(v1a, v1b, v2a + 1, v2b, 0)
                      );
    }
    int pos = min(k/2-1, min(da -1, db-1));
    if (v1a[pos] < v2a[pos])
        return findKth(v1a + pos + 1, v1b, v2a, v2b, k - pos - 1);
    else
        return findKth(v1a, v1b, v2a + pos + 1, v2b, k - pos - 1);
}

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
            int n = nums1.size() + nums2.size();
    if (n % 2)
        return findKth(nums1.begin(), nums1.end(), nums2.begin(), nums2.end() , n / 2);
    else
        return (findKth(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), n / 2 - 1) +
                    findKth(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), n/2)) / 2.0;

    }
};