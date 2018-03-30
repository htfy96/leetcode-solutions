class Solution {
    struct Rec {
        int step;
        int cur;
    };
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        vector<vector<int>> targets(wordList.size());
        
        for (int i=0; i<wordList.size(); ++i)
            for (int j=0; j<wordList.size(); ++j) {
                int diff = 0;
                const string& s1 = wordList[i], s2 = wordList[j];
                for (int k=0; k<s1.size(); ++k) { diff += s1[k] != s2[k]; if (diff > 1) break; }
                if (diff == 1)
                    targets[i].push_back(j);
            }
        int start_idx = find(wordList.begin(), wordList.end(), beginWord) - wordList.begin(),
            end_idx = find(wordList.begin(), wordList.end(), endWord) - wordList.begin();
        vector<bool> v(wordList.size());
        queue<Rec> q;
        q.push(Rec{1, start_idx});
        v[start_idx] = true;
        while (!q.empty()) {
            Rec x= q.front();
            q.pop();
            //cout << "processing " << x.cur << " step=" << x.step << endl;
            if (x.cur == end_idx) return x.step;
            for (int t: targets[x.cur])
                if (!v[t]) {
                    v[t] = true;
                    q.push(Rec{x.step + 1, t});
                }
        }
        return 0;
        
    }
};