class Solution {
   public:
    vector<int> parent, size;
    int findUPar(int u) {
        if (parent[u] == u) return u;
        return parent[u] = findUPar(parent[u]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }

    int kruskal(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
        int sum = 0;
        for (auto& edge : edges) {
            int wt = edge[0];
            int u = edge[1];
            int v = edge[2];
            if (findUPar(u) != findUPar(v)) {
                unionBySize(u, v);
                sum += wt;
            }
        }
        return sum;
    }
    int minCostConnectPoints(vector<vector<int>>& point) {
        vector<vector<int>> edges;
        int n = point.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int x1 = point[i][0];
                int y1 = point[i][1];
                int x2 = point[j][0];
                int y2 = point[j][1];
                int dis = abs(x2 - x1) + abs(y2 - y1);
                edges.push_back({dis, i, j});
            }
        }
        sort(edges.begin(), edges.end());
        return kruskal(n,edges);
    }
};
