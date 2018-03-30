class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        bool ok = false;
        int ans = 0;
        while (!ok) {
            ok = true;
            int best_idx = -1, best_match_idx = -1;
            int best_score = 0;
            for (int i=0; i<row.size(); ++i) {
                if (row[i] / 2 == row[i^1] / 2)
                    continue;
                int cur_val = row[i];
                int match_val = cur_val ^ 1;
                int match_pos = find(row.cbegin(), row.cend(), match_val) - row.cbegin();
                // put match_val from match_pos to i^1
                int cur_idx = i, cur_score;
                ok = false;
                if (row[i^1]^1 == row[match_pos^1])
                    cur_score = 2;
                else
                    cur_score = 1;
                if (cur_score > best_score) {
                    //cout << "updating " << cur_idx << " match_idx" << match_pos << endl;
                    best_score = cur_score;
                    best_idx = cur_idx;
                    best_match_idx = match_pos;
                }
            }
            cout << "Swapping " << (best_idx ^ 1) << " with " << best_match_idx << endl;
            if (!ok) {
                swap(row[best_idx ^ 1], row[best_match_idx]);
                ++ans;
            }
            
        }
        return ans;
    }
};