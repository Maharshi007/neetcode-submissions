class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector(m, 0));
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
            }
        }
        int drow[] = {-1, 0, +1, 0};
        int dcol[] = {0, +1, 0, -1};
        int finalTime = 0;
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            finalTime = max(finalTime, t);
            for (int i = 0; i < 4; i++) {
                int newr = r + drow[i];
                int newc = c + dcol[i];
                if (newr >= 0 && newr < n && newc >= 0 && newc < m && grid[newr][newc] == 1 &&
                    vis[newr][newc] != 2) {
                    q.push({{newr, newc}, t + 1});
                    vis[newr][newc] = 2;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && vis[i][j] != 2) return -1;
            }
        }
        return finalTime;
    }
};
