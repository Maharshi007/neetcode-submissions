class Solution {
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        vis[node] = 1;
        for (auto& v : adj[node]) {
            if (!vis[v]) dfs(v, adj, vis);
        }
    }

   public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int components = 0;
        vector<int> vis(n, 0);
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                components++;
                dfs(i, adj, vis);
            }
        }
        return components;
    }
};
