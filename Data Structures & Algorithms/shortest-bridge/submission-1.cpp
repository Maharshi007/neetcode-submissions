class Solution {
   private:
    void dfs(int row, int col, vector<vector<int>>& vis, queue<pair<pair<int, int>, int>>& q,
             int drow[], int dcol[], vector<vector<int>>& graph) {
        int n = graph.size();
        int m = graph[0].size();
        vis[row][col] = 1;
        q.push({{row, col}, 0});
        for (int i = 0; i < 4; i++) {
            int newRow = row + drow[i];
            int newCol = col + dcol[i];
            if (newRow >= 0 && newRow < n &&
                newCol >= 0 && newCol < m &&
                !vis[newRow][newCol] &&
                graph[newRow][newCol] == 1) {
                dfs(newRow, newCol, vis, q, drow, dcol, graph);
            }
        }
    }

   public:
    int shortestBridge(vector<vector<int>>& graph) {
        int n = graph.size();
        int m = graph[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        bool found = false;
        queue<pair<pair<int, int>, int>> q;
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};
        for (int i = 0; i < n && !found; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && graph[i][j] == 1) {
                    dfs(i, j, vis, q, drow, dcol, graph);
                    found = true;
                    break;
                }
            }
        }
        if (q.empty()) return 0;
        while (!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int flip = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int newRow = row + drow[i];
                int newCol = col + dcol[i];
                if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m &&
                    !vis[newRow][newCol]) {
                    if (graph[newRow][newCol] == 1) {
                        return flip;
                    }
                    vis[newRow][newCol] = 1;
                    q.push({{newRow, newCol}, flip + 1});
                }
            }
        }
        return -1;
    }
};
