class Solution {
   public:
    bool dfs(int node, int parent, vector<int>& vis, vector<vector<int>>& adj) {
        vis[node] = 1;
        for (auto& neighbor : adj[node]) {
            if (neighbor == parent) continue;
            if (vis[neighbor]) return false;
            if (vis[neighbor] == 0) {
                if (!dfs(neighbor, node, vis, adj)) {
                    return false;
                }
            }
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> vis(n, 0);
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        if (edges.size() != n - 1) return false;
        if (!dfs(0, -1, vis, adj)) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            if (!vis[i]) return false;
        }
        return true;
    }
};
