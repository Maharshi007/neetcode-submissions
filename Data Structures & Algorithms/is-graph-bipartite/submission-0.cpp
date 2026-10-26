class Solution {
   private:
    bool dfs(int currNode, int currColor, vector<vector<int>>& graph, vector<int>& color) {
        color[currNode] = currColor;
        for (auto& neighbor : graph[currNode]) {
            if (color[neighbor] == color[currNode]) return false;
            if (color[neighbor] == -1) {
                int colorOfNeighbor = 1 - currColor;
                if (!dfs(neighbor, colorOfNeighbor, graph, color)) return false;
            }
        }
        return true;
    }

   public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for (int i = 0; i < n; i++) {
            if (color[i] == -1)
                if (!dfs(i, 0, graph, color)) return false;
        }
        return true;
    }
};