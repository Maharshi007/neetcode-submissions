class Solution {
    typedef pair<int, pair<int, int>> p;
   public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        queue<p> q;
        vector<int> dist(n, INT_MAX);
        for (auto& edge : flights) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
        }
        dist[src] = 0;
        q.push({0, {src, 0}});  //{stops,{node,dist}}
        while (!q.empty()) {
            int stops = q.front().first;
            int node = q.front().second.first;
            int wt = q.front().second.second;
            q.pop();
            if (stops > k) continue;
            for (auto& [v, edgeWt] : adj[node]) {
                int newEdgeWt = wt + edgeWt;
                if (dist[v] > newEdgeWt && stops <= k) {
                    dist[v] = newEdgeWt;
                    q.push({stops + 1, {v, newEdgeWt}});
                }
            }
        }
        if (dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};