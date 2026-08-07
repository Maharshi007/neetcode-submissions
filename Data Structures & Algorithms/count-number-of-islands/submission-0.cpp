class Solution {
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& vis, int i, int j, int row, int col) {
        if (i < 0 || j < 0 || i >= row || j >= col || vis[i][j] || grid[i][j] == '0') return;
        vis[i][j] = 1;
        dfs(grid, vis, i + 1, j, row, col);
        dfs(grid, vis, i - 1, j, row, col);
        dfs(grid, vis, i, j + 1, row, col);
        dfs(grid, vis, i, j - 1, row, col);
    }

   public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1' && !vis[i][j]) {
                    islands++;
                    dfs(grid, vis, i, j, n, m);
                }
            }
        }
        return islands;
    }
};
