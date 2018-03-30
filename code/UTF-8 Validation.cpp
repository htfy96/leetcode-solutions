class Solution {
public:
    bool validUtf8(vector<int>& data) {
        const int n = data.size();
        
        static const int MASK[] = {0, 0x80, 0xe0, 0xf0, 0xf8};
        static const int PREFIX[] = {0, 0x0, 0xc0, 0xe0, 0xf0};
        static const int TRAILING_MASK = 0xc0, TRAILING_PREFIX = 0x80;
        
        int pos = 0;
        while (pos < n)
        {
            int len = -1;
            for (int i=1; i<=4; ++i)
                if ((data[pos] & MASK[i]) == PREFIX[i])
                {
                    len = i;
                    break;
                }
            cout << "Found len = " << len << endl;
            if (len == -1)
                return false;
            if (pos + len > n)
                return false;
            for (int k = pos+1; k<pos+len; ++k)
                if ((data[k] & TRAILING_MASK) != TRAILING_PREFIX)
                    return false;
            pos += len;
        }
        return true;
    }
};