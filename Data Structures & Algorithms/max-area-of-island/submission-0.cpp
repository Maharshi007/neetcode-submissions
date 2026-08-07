class Solution {
    int dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& vis, int row, int col) {
        if (i < 0 || j < 0 || i >= row || j >= col || vis[i][j] || grid[i][j] == 0) return 0;
        vis[i][j] = 1;
        return 1 + dfs(grid, i + 1, j, vis, row, col) + dfs(grid, i - 1, j, vis, row, col) +
               dfs(grid, i, j + 1, vis, row, col) + dfs(grid, i, j - 1, vis, row, col);
    }

   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int islands = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int maxArea = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    maxArea = max(maxArea, dfs(grid, i, j, vis, n, m));
                }
            }
        }
        return maxArea;
    }
};