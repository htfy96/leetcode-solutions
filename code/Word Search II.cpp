#define _GLIBCXX_CONCEPT_CHECKS
class Solution {

    struct Node {
        map<char, Node> chs;
        bool terminal = false;
    };
    
    struct pairHasher {
        size_t operator()(const pair<int, int>& p) const {
            return p.first ^ p.second;
        }
    };
    Node head;
    int max_depth;
    void add(const string& s) {
        Node *cur = &head;
        for (int i=0; i<s.size(); ++i)
            cur = &cur->chs[s[i]];
        cur->terminal = true;
    }
    
    vector<string> search(vector<vector<char>>& board, int x, int y, Node& cur, string& cur_str, unordered_set<pair<int, int>, pairHasher>& visited) {
        static const int dx[] = {0, 0, -1, 1},
        dy[] = {-1, 1, 0, 0};
        vector<string> ans;
        //if (cur_str.length() > max_depth) return {};
        //cout << " >>> searching x=" << x << " y=" << y << " cur_str=" << cur_str << endl;
        if (cur.terminal)
        {
            ans.push_back(cur_str);
        }


            
            for (int i=0; i<4; ++i) {
                int newx= x + dx[i], newy = y + dy[i];
                /* cout << "> In current chs:";
                for (auto&& it:cur.chs) {
                    cout << (char)it.first << " ";
                }
                cout << endl; 
                cout <<" i=" << i << " newx=" << newx << " newy=" << newy << endl; */
                if (newx < 0 || newy < 0 || newx >= board.size() || newy >= board[0].size()) continue;
                if (visited.find(make_pair(newx, newy)) != visited.end()) continue;
                if (cur.chs.find(board[newx][newy]) == cur.chs.end()) continue;
                visited.insert(make_pair(newx, newy));
                cur_str.push_back(board[newx][newy]);
                Node new_cur = cur.chs[board[newx][newy]];
                auto result = search(board, newx, newy, new_cur, cur_str, visited);
                move(result.begin(), result.end(), back_inserter(ans));
                cur_str.pop_back();
                visited.erase(make_pair(newx, newy));
            }
            

        return ans;
            
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        max_depth= 0;
        sort(words.begin(), words.end());
        words.erase(unique(words.begin(), words.end()), words.end());
        for (auto&& w: words) {
            add(w);
            max_depth = max(max_depth, (int)w.size());
        }
        if (board.empty()) return {};
        int m = board.size(), n = board[0].size();
        vector<bool> found(words.size()); int remain_found = words.size();
        for (int i=0; i<m; ++i)
            for (int j=0; j<n; ++j)
            {
                string cur_str;
                unordered_set<pair<int, int>, pairHasher> up;
                auto it = head.chs.find(board[i][j]);
                if (it == head.chs.end()) continue;
                cur_str = board[i][j];
                up.insert(make_pair(i, j));
                auto result = search(board, i, j, it->second, cur_str, up);
                cout << "after search i=" << i << " j=" << j << endl;
                for (auto&& str: result) {
                    cout << " > " << str << endl;
                    for (int k=0; k<words.size(); ++k) if (str == words[k]) {
                        if (!found[k]) --remain_found;
                        found[k] = true;
                    }
                }
                cout << "remain_found=" << remain_found << endl;
                if (!remain_found) break;
            }
        vector<string> ans;
        for (int i=0; i<words.size(); ++i)
            if (found[i])
                ans.push_back(words[i]);
        return ans;
    }
};