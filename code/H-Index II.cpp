class Solution {
public:
    int hIndex(vector<int>& citations) {
        int ans = 0;
        for (int i=citations.size()-1; i>=0; --i)
        {
            int idx = citations.size() - i;
            if (citations[i] >= idx)
                ans = idx;
            else
                break;
        }
        return ans;
    }
};