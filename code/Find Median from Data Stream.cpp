
class MedianFinder {
    list<vector<int>> l;
    int size = 0;
    static const int N = 64;
    void insert_v(vector<int> &v, int x)
    {
        v.resize(v.size() + 1); int i;
        for (i = v.size() - 1; i>=1; --i)
            if (v[i-1] > x)
                v[i] = v[i-1];
            else
            {
                v[i] = x;
                break;
            }
        if (!i) v[0] = x;
    }
public:
    /** initialize your data structure here. */
    MedianFinder() {
        l.clear();
        size = 0;
    }
    
    void addNum(int num) {
        if (l.empty())
            l.push_back(vector<int> {num});
        else
            for (auto it = l.begin() ; it != l.end(); ++it)
                if (next(it) == l.end() || num < *next(it)->begin())
                {
                    insert_v(*it, num);
                    if (it->size() > 2 * N)
                    {
                        vector<int> new_v(it->begin() + N, it->end());
                        it->resize(N);
                        l.insert(next(it), std::move(new_v));
                    }
                    break;
                }
        ++size;
      //  cout << "Added " << num << endl;
    }
    
    double findMedian() {
        int cnt = 0;
        int sum = 0; /*
        for (auto &&block: l)
        {
            cout << "Block: "; for(int i: block) cout << i << ",";
            cout << " \t";
        }
        cout << endl; */
        for (auto it = l.begin(); it != l.end(); ++it)
        {
            int r = cnt + it->size();
            if (size / 2 >= cnt && size / 2 < r)
                sum += (*it)[size / 2 - cnt];
            if (size % 2 == 0)
                if (size / 2 - 1 >= cnt && size / 2 - 1 < r)
                    sum += (*it)[size / 2 - 1 - cnt];
            cnt = r;
        }
        //cout << "Found!" << endl;
        return size % 2 ? sum : sum / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */