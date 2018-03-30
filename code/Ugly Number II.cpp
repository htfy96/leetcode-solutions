class Solution {
    inline int countUglyNoLargerThan(int x)
    {
        return x > 0 ? x / 2 + x/3 + x/5 - x/6 - x/10 - x/15 + x/60 + 1 : 0;
    }
public:
    int nthUglyNumber(int n) {
        vector<int> v; v.push_back(1);
        int a[3] = {0, 0, 0};
        const int w[3] = {2, 3, 5};
        while (v.size() < n)
        {
            int min = INT_MAX;
            int mini = -1;
            for (int i=0; i<3; ++i)
                if (v[a[i]] * w[i] < min)
                {
                    min = v[a[i]] * w[i];
                    mini = i;
                }
            for (int i=0; i<3; ++i)
                if (v[a[i]] * w[i] == min)
                    ++a[i];
            v.push_back(min);
        }
        //for (int i=0; i<n; ++i) cout << v[i] << " ";
        return v[n-1];
    }
};