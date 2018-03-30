class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int cnt[10000];
        memset(cnt, 0x3f, sizeof(cnt));
        
        cnt[0] = 0;
        for (int coin: coins)
        {
            for (int v=0; v<10000; ++v)
                if (v-coin >= 0)
                    cnt[v] = min(cnt[v], cnt[v-coin] + 1);
        }
        if (cnt[amount] < 100000)
            return cnt[amount];
        else
            return -1;
    }
};