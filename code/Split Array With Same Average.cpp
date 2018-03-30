
class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
            int s = accumulate(A.cbegin(), A.cend(), 0);
            vector<bool> v((A.size() + 1) * (s+1));
            #define idx(i, j) ((i) * (s+1) + (j))
            v[idx(0, 0)] = true;
            for (int i=0; i<A.size(); ++i)
                for (int j=A.size() - 1; j>=0; --j)
                    for (int k=0; k<=s; ++k)
                        if (v[idx(j, k)])
                            v[idx(j+1, k + A[i])] = true;
            for (int j=1; j<=A.size() - 1; ++j)
                for (int k=0; k<=s; ++k)
                    if (v[idx(j, k)])
                {
                    int c1 = j, s1 = k, c2 = A.size() - j, s2 = s - k;
                    if (fabs(s1 * 1.0 / c1 - s2 * 1.0 / c2) < 1e-6)
                    {
                        return true;
                    }
                }
        return false;
    }
};