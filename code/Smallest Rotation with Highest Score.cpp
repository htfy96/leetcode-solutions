class FenwickTree
{
    vector<int> d;
    static int lowbit(int x) {
        return x & (-x);
    }
    public:
    FenwickTree(int cap): d(cap) {}
    int get_prefix_sum(int w) { // [1, w]
        int ans = 0;
        while (w > 0)
        {
            ans += d[w];
            w -= lowbit(w);
        }
        return ans;
    }  
    void add(int pos, int w) {
        while (pos < d.size()) {
            d[pos] += w;
            //cout << "pos=" << pos << endl;
            pos += lowbit(pos);
        }
    }
};

class Solution {
public:
    int bestRotation(vector<int>& A) {
        
        const int OFFSET = A.size() + 1;
        FenwickTree set_a(OFFSET + A.size() + 1), set_b(OFFSET + A.size() + 1);
        for (int i=0; i<A.size(); ++i)
            set_b.add(A[i] - i + OFFSET, 1);
        int ans = INT_MIN, ansk = -1;
        for (int k=0; k<=A.size(); ++k) {
            int curans = 0;
            // setA: A_i <= i + A.size() - K
            //       A_i - i <= A.size() - K
            curans += set_a.get_prefix_sum((int)A.size() - k + OFFSET);
            // setB: A_i <= i - K
            // A_i - i <= -K
            curans += set_b.get_prefix_sum(-k +  OFFSET);
            if (curans > ans) {
                ans = curans;
                ansk = k;
            }
            if (k < A.size()) {
                set_a.add(A[k] - k + OFFSET, 1);
                set_b.add(A[k] - k + OFFSET, -1);
            }
        }
        return ansk;
        
    }
};