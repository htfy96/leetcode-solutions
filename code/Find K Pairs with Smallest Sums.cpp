    struct MyLess {
    bool operator() (const pair<int, int> &p1, const pair<int, int> &p2) const
    {
        return p1.first + p1.second < p2.first + p2.second;
    }
    };
    

        struct myhash
        {
            hash<int> h;
            size_t operator() (const pair<int, int> &p) const
            {
                return (unsigned) h(p.first) * 13133 + (unsigned) h(p.second);
            }
        };
    
class Solution {

public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        multiset<pair<int, int>, MyLess> s;
        unordered_set<pair<int, int>, myhash> e;
        for (int i=0; i<nums1.size(); ++i)
        {
            int p1 = nums1[i];
            for (int j=0; j<nums2.size(); ++j)
            {
              //  cout << i << " j=" << j << endl;
                int p2 = nums2[j];
                if (s.size() == k && s.rbegin()->first + s.rbegin()->second <= p1 + p2)
                    break;
                else
                {
                  //  if (e.find(make_pair(p1, p2)) == e.end())
                //    {
                    //    cout << "inserting " << p1 << "," << p2 << endl;
                        s.insert(make_pair(p1, p2));
                    //    e.insert(make_pair(p1, p2));
                        if (s.size() > k) { /* cout << "erasing last: " << s.rbegin()->first << "," << s.rbegin()->second << endl;*/ s.erase(prev(s.end())); }
                 //   }
                }
            }
        }
        vector<pair<int, int>> ans;
        ans.reserve(k);
        copy(s.begin(), s.end(), back_inserter(ans));
        return ans;
    }
};