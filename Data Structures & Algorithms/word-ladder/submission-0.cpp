class Solution {
    void bfs(string& curr, queue<string>& q, unordered_set<string>& st) {
        for (int i = 0; i < curr.size(); i++) {
            char original = curr[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                if (original == ch) continue;
                curr[i] = ch;
                if (st.find(curr) != st.end()) {
                    q.push(curr);
                    st.erase(curr);
                }
                curr[i] = original;
            }
        }
    }

   public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord == endWord) return 0;
        unordered_set<string> st(wordList.begin(), wordList.end());
        if (st.find(endWord) == st.end()) return 0;
        queue<string> q;
        q.push(beginWord);
        int level = 1;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                string curr = q.front();
                q.pop();
                if (curr == endWord) return level;
                bfs(curr, q, st);
            }
            level++;
        }
        return 0;
    }
};
