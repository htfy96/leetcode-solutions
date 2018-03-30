class Solution {
    static constexpr long long modulo = 1000000007;
    static void add_and_modulo(int& val, int add)
    {
        val = ((long)val + add) % modulo;
    }
public:
    int numTilings(int N) {
        vector<array<int, 4>> a(N+1);
        a[0][0] = 1;
        for (int i=0; i<N; ++i)
            for (int state = 0; state < 4; ++state) {
                //cout << "a[" << i << "][" << state << "] = " << a[i][state] << endl;
                switch(state) {
                    case 0:
                        add_and_modulo(a[i+1][0], a[i][0]);
                        add_and_modulo(a[i+1][1], a[i][0]);
                        add_and_modulo(a[i+1][2], a[i][0]);
                        add_and_modulo(a[i+1][3], a[i][0]);
                        break;
                    case 1:
                        add_and_modulo(a[i+1][2], a[i][1]);
                        add_and_modulo(a[i+1][3], a[i][1]);
                        break;
                    case 2:
                        add_and_modulo(a[i+1][1], a[i][2]);
                        add_and_modulo(a[i+1][3], a[i][2]);
                        break;
                    case 3:
                        add_and_modulo(a[i+1][0], a[i][3]);
                        break;
                }
            }
        return a[N][0];
    }
};