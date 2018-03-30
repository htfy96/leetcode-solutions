class Solution {
    struct Rec {
        int data;
        int l, idx;
        bool operator==(const Rec& other) const {
            return data == other.data;
        }
        bool operator<(const Rec& other) const {
            return data < other.data;
        }
    };
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        multiset<Rec> s;
        for (int i=0; i<nums.size(); ++i)
            s.insert(Rec{nums[i][0], i, 0});
        // int ans = INT_MAX;
        int best_left = s.begin()->data, best_right = s.rbegin()->data;
        for (;;) {
            Rec left = *s.begin();
            if (left.idx + 1 == nums[left.l].size()) break;
            s.erase(s.begin());
            s.insert(Rec{nums[left.l][left.idx + 1], left.l, left.idx + 1});
            int new_left = s.begin()->data, new_right = s.rbegin()->data;
            /*cout << "pop_out " << left.data << " list=" << left.l << " idx=" << left.idx << "\t";
            cout << "push_in " << nums[left.l][left.idx + 1] << " idx=" << left.idx + 1 << "\t";
            cout << "Now best_left = " << new_left << " best_right=" << new_right << endl;*/
            if (new_right - new_left < best_right - best_left) {
                best_left = new_left;
                best_right = new_right;
            }
        }
        return {best_left, best_right};
    }
};