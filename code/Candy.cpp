class Solution {
    #define left_greater(i) (i>0 && ratings[i-1] > ratings[i])
    #define right_greater(i) (i < n-1 && ratings[i+1] > ratings[i])
public:
    int candy(vector<int>& ratings) {
        vector<int> ans(ratings.size());
        queue<int> q;
        size_t n = ratings.size();
        for (size_t i=0; i<n; ++i)
        {
            if ((i==0 ||ratings[i-1] >= ratings[i]) && (i == n-1 || ratings[i+1] >= ratings[i]))
            {
                q.push(i);
                ans[i] = 1;
            }
        }
        while (!q.empty())
        {
            int x = q.front();
            q.pop();
            if (x+1<n && !ans[x+1] || right_greater(x)) q.push(x+1);
            if (right_greater(x))
                ans[x+1] = max(ans[x+1], ans[x] + 1);
            if (x > 0 && !ans[x-1] || left_greater(x)) q.push(x-1);
            if (left_greater(x))
                ans[x-1]= max(ans[x-1], ans[x] + 1);
        }
       // for (auto x:ans) cout << x << " ";
        return accumulate(ans.begin(), ans.end(), 0);
    }
};