#define printc(c) do { for(int o=0; o<c.size(); ++o) cout << c[o] << " "; cout << endl; } while(0);
class Solution {
    deque<int> pick(const vector<int>& v, int k)
    {
        deque<int> q;
        int cnt = 0;
        for (int i=0; i<v.size(); ++i)
        {
            while (cnt< v.size()-k && !q.empty() && q.back() < v[i]) { cnt++; q.pop_back(); }
            q.push_back(v[i]);
        }
        //printc(v); cout << k << endl;
        //printc(deque<int>(q.begin(), q.begin()+k));
        return deque<int>(q.begin(), q.begin() + k);
    }
    bool le(const deque<int> &d1, const deque<int> &d2)
    {
        for (int i=0; i<min(d1.size(), d2.size()); ++i)
            if (d1[i] < d2[i])
                return true;
            else if (d1[i] > d2[i])
                return false;
        return d1.size() <= d2.size();
    }
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        deque<int> a, b;
        string maxss = "";
        vector<int> maxvs;
        for (int n=0; n<=k; ++n)
        {
            if (n > nums1.size() || k-n > nums2.size()) continue;
            a = pick(nums1, n);
            b = pick(nums2, k-n);
         string ss;
         vector<int> s;
         while (!a.empty() || !b.empty())
        {
            while (!a.empty() && le(b, a))
            {
                s.push_back(a.front());
                ss.push_back('0' + a.front());
                a.pop_front();
            }
            while (!b.empty() && le(a, b))
            {
                s.push_back(b.front());
                ss.push_back('0' + b.front());
                b.pop_front();
            }
        }
        //cout << "SS= " << ss << endl;
         if (ss>maxss)
        {
            maxss = ss;
            maxvs = s;
        }
    }
    
    return maxvs;
            
    }
};