class Solution {
   public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        // KAHN'S ALGO - BFS
        // Cycle Detection => empty vector
        // No cycle then push the courses
        vector<vector<int>> graph(n);
        vector<int> indegree(n, 0);
        queue<int> q;
        vector<int> ans;
        for (auto& edge : prerequisites) {
            int u = edge[0];
            int v = edge[1];
            graph[v].push_back(u);
            indegree[u]++;
        }
        for (int i = 0; i < n; i++) {
            if (!indegree[i]) q.push(i);
        }
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for (auto& v : graph[node]) {
                indegree[v]--;
                if (!indegree[v]) q.push(v);
            }
        }
        if (ans.size() == n) return ans;
        return {};
    }
};
