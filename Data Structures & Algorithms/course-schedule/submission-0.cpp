class Solution {
   private:
    bool cycleDetect(int node, vector<int>& vis, vector<vector<int>>& graph) {
        vis[node] = 1;
        for (auto& v : graph[node]) {
            if (vis[v] == 1) return true;
            if (!vis[v])
                if (cycleDetect(v, vis, graph)) return true;
        }
        vis[node] = 2;
        return false;
    }

   public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        // TOPOLOGICAL SORT][DAG] - cycleDetection using DFS
        vector<vector<int>> graph(n);
        vector<int> vis(n, 0);
        for (auto& edge : prerequisites) {
            int u = edge[0];
            int v = edge[1];
            graph[v].push_back(u);
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (cycleDetect(i, vis, graph)) return false;
            }
        }
        return true;
    }
};
