class Solution {
   private:
    bool topoSort(int node, vector<int>& vis, stack<int>& st, vector<vector<int>>& adjList) {
        vis[node] = 1;
        for (auto& v : adjList[node]) {
            if (vis[v] == 1) return true;
            if (!vis[v])
                if (topoSort(v, vis, st, adjList)) return true;
        }
        st.push(node);
        vis[node] = 2;
        return false;
    }

   public:
    string foreignDictionary(vector<string>& words) {
        // DFS
        int n = words.size();
        vector<int> present(26, 0);
        vector<int> vis(26, 0);
        vector<vector<int>> adjList(26);
        stack<int> st;
        string ans;
        for (auto& word : words) {
            for (auto& ch : word) {
                present[ch - 'a'] = 1;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            string str1 = words[i];
            string str2 = words[i + 1];
            int len = min(str1.size(), str2.size());
            bool foundDiff = false;
            for (int k = 0; k < len; k++) {
                if (str1[k] != str2[k]) {
                    int u = str1[k] - 'a';
                    int v = str2[k] - 'a';
                    adjList[u].push_back(v);
                    foundDiff = true;
                    break;
                }
            }
            if (!foundDiff && str1.size() > str2.size()) {
                return "";
            }
        }
        for (int i = 0; i < 26; i++) {
            if (present[i] && !vis[i]) {
                if (topoSort(i, vis, st, adjList)) return "";
            }
        }
        while (!st.empty()) {
            char ch = char(st.top() + 'a');
            ans += ch;
            st.pop();
        }
        return ans;
    }
};
