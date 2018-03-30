class Solution {
    struct Task
    {
        int cnt;
        int next_start;
        friend bool operator<(const Task& a, const Task& b)
        {
            return a.cnt < b.cnt;
        }
        friend bool operator>(const Task& a, const Task& b)
        {
            return a.cnt > b.cnt;
        }
        friend bool operator==(const Task& a, const Task& b)
        {
            return a.cnt == b.cnt;
        }
    };
public:
    int leastInterval(vector<char>& tasks, int n) {
        int t_cnt[26] {};
        for (char c: tasks)
            t_cnt[c-'A']++;
        queue<Task> q;
        priority_queue<Task> pq;
        for (int i=0; i<26; ++i)
            if (t_cnt[i])
                q.push(Task{t_cnt[i], 1});
        int t = 1;
        while (!q.empty() || !pq.empty())
        {
            if (pq.empty()) t = q.front().next_start;
            while (!q.empty() && t >= q.front().next_start)
            {
                Task tt = q.front();
                pq.push(tt);
                q.pop();
            }
            Task tt = pq.top(); pq.pop();
            if (tt.cnt > 1) q.push(Task{tt.cnt - 1, t + n + 1}); t++;
        }
        return t-1;
    }
};