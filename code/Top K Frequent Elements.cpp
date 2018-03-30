class Solution {
    struct Rec {
        int num, cnt;
        bool operator<(const Rec& other) const {
            return cnt != other.cnt ? cnt < other.cnt : num < other.num;
        }
        bool operator==(const Rec& other) const {
            return cnt == other.cnt && num == other.num;
        }
    };
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        priority_queue<Rec> q;
        for (int v: nums) {
            cnt[v]++;
        }
        auto cnt2 = cnt;
        for (int v: nums) {
            if (--cnt2[v] == 0) {
                //cout << "add num=" << v << " cnt=" << cnt[v] << endl;
                q.push(Rec{v, cnt[v]});
            }
        }
        vector<int> ans; ans.reserve(k);
        for (int i=0; i<k; ++i)
        {
            Rec x = q.top();
            q.pop();
            ans.push_back(x.num);
        }
        return ans;
    }
};