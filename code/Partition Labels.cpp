class Solution {
public:
    vector<int> partitionLabels(string S) {
        int rightmost = 0; int left = 0;
        vector<int> ans;
        for (int i=0; i<S.size(); ++i) {
            for (int j=i; j<S.size(); ++j) {
                if (S[j] == S[i])
                rightmost = max(rightmost, j);
            }
            if (i == rightmost) {
                ans.push_back(i - left + 1);
                rightmost = 0;
                left = i + 1;
            }
        }
        return ans;
    }
};