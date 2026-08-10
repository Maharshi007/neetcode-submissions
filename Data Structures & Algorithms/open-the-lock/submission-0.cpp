class Solution {
   public:
    void bfs(string& curr, queue<string>& q, unordered_set<string>& st) {
        for (int i = 0; i < 4; i++) {
            char ch = curr[i];
            char inc = ch == '9' ? '0' : ch + 1;
            char dec = ch == '0' ? '9' : ch - 1;
            curr[i] = inc;
            if (st.find(curr) == st.end()) {
                q.push(curr);
                st.insert(curr);
            }
            curr[i] = dec;
            if (st.find(curr) == st.end()) {
                q.push(curr);
                st.insert(curr);
            }
            curr[i] = ch;
        }
    }
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> st(deadends.begin(), deadends.end());
        string start = "0000";
        if (st.find(start) != st.end()) return -1;
        queue<string> q;
        q.push(start);
        st.insert(start);
        int level = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string curr = q.front();
                if (curr == target) return level;
                q.pop();
                bfs(curr, q, st);
            }
            level++;
        }
        return -1;
    }
};