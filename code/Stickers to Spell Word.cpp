class Solution {
    int ans;
    using CntT alignas(16) = array<unsigned char, 26>;
    struct StickerT
    {
        CntT cnt;
        float match_score;
        bool operator<(const StickerT& other) const {
            return match_score < other.match_score;
        }
        bool operator>(const StickerT& other) const {
            return match_score > other.match_score;
        }
        friend ostream& operator<<(ostream& o, const StickerT& sticker) {
            o << "cnt=";
            for (int i=0; i<sticker.cnt.size(); ++i)
                o << sticker.cnt[i] << " ";
            o << "\t" << "match_score=" << sticker.match_score;
            return o;
        }
    };
    vector<StickerT> sticker_cnts;
    CntT target_cnt{}, cur_cnt;
    int max_depth;
    
    void search(int step, int start_idx) {
        if (step > max_depth) return;
        if (start_idx > sticker_cnts.size()) {
            return;
        }
        if (step > ans)
            return;
        bool ok = true;
        for (int i=0; i<cur_cnt.size(); ++i)
            if (cur_cnt[i] < target_cnt[i])
            {
                ok = false;
                break;
            }
        if (ok) {
            ans = min(ans, step);
            return;
        }
        auto old_cur_cnt = cur_cnt;
        int cur_step = step;
        search(step, start_idx + 1);
        for (;;) {
            const StickerT& cur_sticker = sticker_cnts[start_idx];
            bool has_contribution = false;
            for (int j=0; j<cur_sticker.cnt.size(); ++j) {
                if (cur_cnt[j] < target_cnt[j] && cur_sticker.cnt[j] > 0) {
                    has_contribution = true;
                }
                cur_cnt[j] += cur_sticker.cnt[j];
            }
            
            if (!has_contribution) break;
            cur_step++;
            search(cur_step, start_idx + 1);
        }
        cur_cnt = old_cur_cnt;
    }
public:
    int minStickers(vector<string>& stickers, string target) {
        sticker_cnts.clear();
        fill(target_cnt.begin(), target_cnt.end(), 0);
        for (char c: target)
            target_cnt[c-'a']++;
        for (auto&& sticker: stickers) {
            sticker_cnts.push_back(StickerT{});
            auto&& last_cnt = *sticker_cnts.rbegin();
            for (char c: sticker)
                if (target_cnt[c-'a'])
                    last_cnt.cnt[c-'a']++;
            for (int i=0; i<last_cnt.cnt.size(); ++i) {
                last_cnt.match_score += target_cnt[i] ? min(last_cnt.cnt[i] * 1.0f / target_cnt[i], 1.0f) : 0.0f;
            }
        }
        // cout << "> before=" << sticker_cnts.size() << endl;
        for (int i=0; i<sticker_cnts.size();) {
            bool found_all_no_bad = false;
            for (int j=0; j<sticker_cnts.size(); ++j)
            {
                if (j == i) continue;
                bool all_no_bad = true;
                for (int k=0; k< sticker_cnts[i].cnt.size(); ++k)
                    if (sticker_cnts[j].cnt[k] < sticker_cnts[i].cnt[k])
                        all_no_bad = false;
                if (all_no_bad)
                {
                    sticker_cnts.erase(sticker_cnts.begin() + i);
                    break;
                    found_all_no_bad = true;
                }
            }
            if (!found_all_no_bad)
                ++i;
        }
        // cout << "> after=" << sticker_cnts.size() << endl;
        sort(sticker_cnts.begin(), sticker_cnts.end(), greater<StickerT>());
        bool no_solution = false;
        for (int i=0; i<target_cnt.size(); ++i)
            if (target_cnt[i])
            {
                bool found = false;
                for (int j=0; j<sticker_cnts.size(); ++j)
                    if (sticker_cnts[j].cnt[i])
                        found = true;
                if (!found)
                {
                    no_solution = true;
                    break;
                }
            }
        if (no_solution) return -1;
        
        ans = 19260711;
        fill(cur_cnt.begin(), cur_cnt.end(), 0);
        no_solution = false;
        for (max_depth=1;max_depth < 8 && ans > 19260000;++max_depth)
            search(0, 0);
        return ans > 19260000 ? -1 : ans;
    }
};