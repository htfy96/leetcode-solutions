#define FORTIFY_SOURCE 2
class Solution {
public:
    int uniquePaths(int m, int n) {
        int all = n-1+m-1;
        int mi = min(n-1, m-1);
        vector<int> f(2 * (mi+1));
        for (int i=0; i<=all; ++i)
            for (int j=0; j<=mi; ++j)
            {
                if (!j) { f[(i%2) * (mi+1) + j] = 1; continue; }
                if (j>i) { f[(i%2) * (mi+1) + j] = 0; continue; }
                f[(i%2) * (mi+1) + j] = f[((i+1)%2) * (mi+1) + j] + f[((i+1)%2) * (mi+1) + j-1];
                // cout << "C(" << i << "," << j << ")= " << f[(i%2) * (mi+1) + j] << endl;
            }
       /* cout << "finished" << endl;
        cout << f.size() << " " << f.capacity() << endl; */
        return f[(all % 2) * (mi+1) + mi];        
        
    }
};