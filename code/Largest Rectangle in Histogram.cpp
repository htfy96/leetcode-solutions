class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        stack<int> s;
        s.push(-1);
        heights.push_back(0);
        #define val(x) ((x) >= 0 ? heights[(x)] : 0)
        for (int i=0; i<heights.size(); ++i)
        {
            int v = val(i);
            if (v >= val(s.top())) s.push(i);
            else
            {
                while (v < val(s.top()))
                {
                    int ni = s.top();
                    s.pop();
                    //cout << "ni=" << ni << " left=" << s.top() << " right=" << i << " val=" << (i - s.top() - 1) * val(ni) << endl;
                    ans = max(ans, (i - s.top() - 1) * val(ni));
                }
                s.push(i);
            }
        }
        return ans;
    }
};